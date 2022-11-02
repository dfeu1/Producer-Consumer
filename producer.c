#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "shared.h"

int main() {
    
    int num = 0;
    time_t randVar;
    srand((unsigned) time(&randVar));

    // Allocating shared memory!
    int fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
    // Set size of shared memory by truncate
    ftruncate(fd, SIZE);

    struct table *sh = mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

    // Semaphores used to track table buffer, make consumer run
    sem_t *full = sem_open(sFull, O_CREAT, 0666, 0);
    sem_t *empty = sem_open(sEmpty, O_CREAT, 0666, bSize);
    sem_t *mutex = sem_open(sMutex, O_CREAT, 0666, 1);
    
    int i = 9; // Producer should produce 9 times
    while(i--) {
        // Check table is empty and check crit 
        sem_wait(empty);
        // sleep for a random time
        sleep(rand()% 2 + 1);
        sem_wait(mutex);
        
        // 0-50 random number inserted in buffer
        num = rand() % 50;
        sh->buffer[sh->in] = num;

        printf("produced %d [%d]\n", sh->buffer[sh->in], sh->in);
        sh->in = (sh->in + 1) % bSize; // 0 when max size

        sem_post(mutex); // Lock
        sem_post(full);  // Decrement full s
    }

    // Close and unlink semaphores
    sem_close(full);
    sem_close(empty);
    sem_close(mutex);
    sem_unlink(sFull);
    sem_unlink(sEmpty);
    sem_unlink(sMutex);


    // Close the shared memory object
    munmap(sh, SIZE);
    close(fd);
    shm_unlink(NAME);

    return 0;
}
