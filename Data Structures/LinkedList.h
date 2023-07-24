/*H**********************************************************************
* FILENAME :        LinkedList.h
*
* DESCRIPTION :
*       Implementation of an ArrayList
*
* AUTHOR :    Saher Anwar Ziauddin
* Source: My implementation of ArrayList from previous course:
*         https://git.cs.dal.ca/courses/2023-winter/csci-2122/lab6/ziauddin.git
*H*/

#ifndef TEST_LINKEDLIST_H
#define TEST_LINKEDLIST_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node{
    void* data;
    struct _Node* next;
    struct _Node* prev;
}Node;

typedef struct _LinkedList{
    Node* first;
    Node* last;
    int size;
    int itemSize;
    char* type;
}LinkedList;

LinkedList* llist_initialize(int, char*);
bool llist_add_at(LinkedList*, int, void*);
bool llist_add_first(LinkedList*, void*);
bool llist_add_last(LinkedList*, void*);
void* llist_get(LinkedList*, int);
int llist_index_of(LinkedList*, void*);
void* llist_remove(LinkedList*, int);
void* llist_remove_first(LinkedList*);
void* llist_remove_last(LinkedList*);
bool llist_destroy(LinkedList*);
void llist_print(LinkedList*);
void llist_print_reverse(LinkedList* linkedList);

#endif //TEST_LINKEDLIST_H
