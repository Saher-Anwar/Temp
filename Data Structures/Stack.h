/*H**********************************************************************
* FILENAME :        Stack.h
*
* DESCRIPTION :
*       Implementation of an ArrayList
*
* AUTHOR :    Saher Anwar Ziauddin
* Source: My implementation of ArrayList from previous course:
*         https://git.cs.dal.ca/courses/2023-winter/csci-2122/lab6/ziauddin.git
*H*/

#ifndef TEST_STACK_H
#define TEST_STACK_H

#include "LinkedList.h"

typedef struct _Stack{
    LinkedList *linkedList;
}Stack;

Stack* stack_initialize(int, char*);
bool stack_push(Stack*, void*);
void* stack_pop(Stack*);
void* stack_peek(Stack*);
int stack_size(Stack*);
bool stack_contains(Stack*, void*);
bool stack_destroy(Stack*);

#endif //TEST_STACK_H
