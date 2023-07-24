/*H**********************************************************************
* FILENAME :        ArrayList.h
*
* DESCRIPTION :
*       Implementation of an ArrayList
*
* AUTHOR :    Saher Anwar Ziauddin
* Source: My implementation of ArrayList from previous course:
*         https://git.cs.dal.ca/courses/2023-winter/csci-2122/lab5/ziauddin.git
*H*/

#ifndef TEST_ARRAYLIST_H
#define TEST_ARRAYLIST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _AList{
    void ** arr;
    int currSize;
    int maxSize;
    int itemByteSize;
    char* datatype;
}ArrayList;

ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool alist_destroy(ArrayList*);
bool alist_resize(ArrayList*);

// test
void alist_print(ArrayList*);

#endif //TEST_ARRAYLIST_H
