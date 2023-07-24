/*H**********************************************************************
* FILENAME :        PriorityQueue.h
*
* DESCRIPTION :
*       Implementation of a PriorityQueue
*
* AUTHOR :    Saher Anwar Ziauddin
*H*/

#ifndef TEST_PRIORITYQUEUE_H
#define TEST_PRIORITYQUEUE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _PriorityNode{
    void* data;
    int priority;
    struct _PriorityNode* next;
}PriorityNode;

typedef struct _PriorityQueue{
    PriorityNode* head;
    PriorityNode* tail;
    int size;
    int typeSize;
}PriorityQueue;

PriorityQueue* pq_init(int typeSize);
bool pq_enqueue(PriorityQueue* pq, void* data, int priority);
void* pq_dequeue(PriorityQueue* pq);
void* pq_peek(PriorityQueue* pq);
void* pq_removeAt(PriorityQueue* pq);
bool pq_destroy(PriorityQueue* pq);
bool pq_is_empty(PriorityQueue* pq);

void pq_print(PriorityQueue* pq);
#endif //TEST_PRIORITYQUEUE_H
