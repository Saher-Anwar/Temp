/*H**********************************************************************
* FILENAME :        Stack.c
*
* DESCRIPTION :
*       Implementation of an ArrayList
*
* AUTHOR :    Saher Anwar Ziauddin
* Source: My implementation of ArrayList from previous course:
*         https://git.cs.dal.ca/courses/2023-winter/csci-2122/lab6/ziauddin.git
*H*/

#include "Stack.h"

Stack* stack_initialize(int itemSize, char* datatype){
    Stack *stack = calloc(1, sizeof(Stack));
    stack->linkedList = llist_initialize(itemSize, datatype);
    return stack;
}

bool stack_push(Stack* stack, void* data){
    if(stack == NULL){
        printf("Stack is NULL (push)\n");
        return false;
    }

    if(data == NULL){
        printf("Data is NULL (push)\n");
        return false;
    }

    return llist_add_first(stack->linkedList, data);
}

void* stack_pop(Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL (pop)\n");
        return NULL;
    }

    return llist_remove_first(stack->linkedList);
}

void* stack_peek(Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL (peek)\n");
        return NULL;
    }

    return llist_get(stack->linkedList, 0);
}

int stack_size(Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL (size)\n");
        return -1;
    }

    return stack->linkedList->size;
}

bool stack_contains(Stack* stack, void* item){
    if(stack == NULL){
        printf("Stack is NULL (contains)\n");
        return false;
    }

    if(item == NULL){
        printf("Item is NULL (contains)\n");
        return false;
    }

    if(llist_index_of(stack->linkedList, item) != -1){
        return true;
    }

    return false;
}

bool stack_destroy(Stack* stack){
    if(stack == NULL){
        printf("Stack is NULL (destroy)\n");
        return false;
    }

    llist_destroy(stack->linkedList);
    free(stack);

    return true;
}
