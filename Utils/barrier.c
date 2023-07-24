//
// Created by saher on 20/07/2023.
//

#include "barrier.h"
void barrier_init(barrier_t* barrier, int n) {
    pthread_mutex_init(&barrier->mutex, NULL);
    pthread_cond_init(&barrier->cond1, NULL);
    pthread_cond_init(&barrier->cond2, NULL);
    barrier->max_threads = n;
    barrier->cur_threads = 0;
    barrier->phase = 0;
}

void barrier_wait(barrier_t* barrier) {
    pthread_mutex_lock(&barrier->mutex);

    barrier->cur_threads++;
    if (barrier->cur_threads == barrier->max_threads) {
        barrier->cur_threads = 0;
        barrier->phase = 1 - barrier->phase;  // Alternating between 0 and 1

        // Broadcasting on the current phase's condition variable
        if (barrier->phase == 0) {
            pthread_cond_broadcast(&barrier->cond2);
        } else {
            pthread_cond_broadcast(&barrier->cond1);
        }
    } else {
        // Waiting on the current phase's condition variable
        if (barrier->phase == 0) {
            pthread_cond_wait(&barrier->cond1, &barrier->mutex);
        } else {
            pthread_cond_wait(&barrier->cond2, &barrier->mutex);
        }
    }
    pthread_mutex_unlock(&barrier->mutex);
}

void barrier_done(barrier_t* barrier) {
    pthread_mutex_lock(&barrier->mutex);
    barrier->max_threads--;
    if (barrier->cur_threads == barrier->max_threads) {
        barrier->cur_threads = 0;
        barrier->phase = 1 - barrier->phase;

        if (barrier->phase == 0) {
            pthread_cond_broadcast(&barrier->cond2);
        } else {
            pthread_cond_broadcast(&barrier->cond1);
        }
    }
    pthread_mutex_unlock(&barrier->mutex);
}