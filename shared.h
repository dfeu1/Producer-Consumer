#include <stdlib.h>
#include <semaphore.h>

#ifndef _SHARED_H
#define _SHARED_H

static const char* sEmpty = "empty";
static const char* sMutex = "mutex";
static const char* sFull = "full";
static const char* NAME = "PC";

static const int bSize = 2;
struct table {   // Table is sized 2 [0, and 1]
    int buffer[2];
    int in;
    int out;
};

static const int SIZE = sizeof(struct table);

#endif