//
// Created by saher on 20/07/2023.
//

#ifndef PROSIM_BARRIER_H
#define PROSIM_BARRIER_H
#include <pthread.h>

typedef struct _barrier{
    pthread_mutex_t mutex;
    pthread_cond_t cond1, cond2;
    int max_threads, cur_threads;
    int phase;
} barrier_t;

void barrier_init(barrier_t* barrier, int n);
void barrier_wait(barrier_t* barrier);
void barrier_done(barrier_t* barrier);

#endif //PROSIM_BARRIER_H
