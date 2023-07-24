/*H**********************************************************************
* FILENAME :        PriorityQueue.h
*
* DESCRIPTION :
*       Implementation of a PriorityQueue
*
* AUTHOR :    Saher Anwar Ziauddin
*H*/
#include "PriorityQueue.h"


// Create a PriorityQueue
PriorityQueue* pq_init(int typeSize){
    PriorityQueue* pq = calloc(1, sizeof(PriorityQueue));
    pq->size = 0;
    pq->typeSize = typeSize;

    return pq;
}

// Add some data to the PriorityQueue based on its priority
bool pq_enqueue(PriorityQueue* pq, void* data, int priority){
    if(data == NULL) return false;

    // create new PriorityNode and initialize it
    PriorityNode* newNode = calloc(1, sizeof(PriorityNode));
    newNode->data = calloc(1, pq->typeSize);
//    memcpy(newNode->data, data, pq->typeSize);
    newNode->data = data;
    newNode->priority = priority;

    // if head is null, this node becomes the head
    if(pq->head == NULL){
        pq->head = newNode;
        pq->tail = newNode;
    } else{
        // otherwise, find where the new node needs to be inserted
        PriorityNode* temp = pq->head;
        PriorityNode* prev = NULL;

        while(temp != NULL && newNode->priority >= temp->priority){
            prev = temp;
            temp = temp->next;
        }

        // insert the new node accordingly (1. at the end, 2. at the start, 3. in the middle)
        if(temp == NULL){
            prev->next = newNode;
            pq->tail = newNode;
        } else if(temp == pq->head){
            newNode->next = pq->head;
            pq->head = newNode;
        } else{
            newNode->next = temp;
            prev->next = newNode;
        }
    }

    // increment size
    pq->size++;
    return true;
}

// remove node from the head of the PriorityQueue
void* pq_dequeue(PriorityQueue* pq){
    if(pq == NULL || pq->head == NULL) return NULL;

    // 2 cases: case 1 -> only 1 item in PriorityQueue ; case 2 -> more than 1 item
    PriorityNode* temp;
    if(pq->head == pq->tail){
        temp = pq->head;
        pq->head = NULL;
        pq->tail = NULL;
    } else{
        temp = pq->head;
        pq->head = pq->head->next;
    }

    // decrement size
    pq->size--;
    return temp;
}

// return the front most item in the PriorityQueue
void* pq_peek(PriorityQueue* pq){
    if(pq == NULL || pq->head == NULL) return NULL;

    PriorityNode* temp = pq->head;
    return temp;
}

// check if PriorityQueue is empty
bool pq_is_empty(PriorityQueue* pq){
    return pq->size <= 0;
}

// deallocate PriorityQueue
bool pq_destroy(PriorityQueue* pq){
    if(pq == NULL) return false;

    PriorityNode* temp = pq->head;

    while(temp != NULL){
        free(temp->data);
        temp = temp->next;
    }

    free(pq);

    return true;
}

// iterate over and print PriorityQueue
void pq_print(PriorityQueue* pq){
    if(pq == NULL) return;

    PriorityNode* temp = pq->head;
    while(temp != NULL){
        printf("%d->", *(int*)temp->data);
        temp = temp->next;
    }
}