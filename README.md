# Producer-Consumer Problem: Operating Systems

Due 11/1 | Programming Assignment #1

The producer generates items and puts items onto the table. The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer.  Mutual exclusion should be considered. We use threads in the producer program and consumer program. Shared memory is used for the “table”.

## How to Compile (Linux Terminal)

$ gcc producer.c -pthread -lrt -o producer                                                                                                                 
$ gcc consumer.c -pthread -lrt -o consumer                                                                                                                 
$ ./producer & ./consumer &

### Examples

Examples of the programming runnning are given as follows: (9 produces, 9 consumes)

```
produced 43 [0]
produced 59 [1]
consumed 43 [0]
consumed 59 [1]
produced 49 [0]
consumed 49 [0]
produced 67 [1]
produced 65 [0]
consumed 67 [1]
produced 65 [1]
consumed 65 [0]
produced 92 [0]
consumed 65 [1]
consumed 92 [0]
produced 50 [1]
produced 76 [0]
consumed 50 [1]
consumed 76 [0]
Finished, enter to exit.
```

```
produced 77 [0]
produced 26 [1]
consumed 77 [0]
produced 71 [0]
consumed 26 [1]
produced 65 [1]
consumed 71 [0]
consumed 65 [1]
produced 5 [0]
produced 98 [1]
consumed 5 [0]
produced 70 [0]
consumed 98 [1]
consumed 70 [0]
produced 19 [1]
produced 46 [0]
consumed 19 [1]
consumed 46 [0]
Finished, enter to exit.
```

## Authors

* **Daniel Feuer** 
