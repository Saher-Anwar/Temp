/*H**********************************************************************
* FILENAME :        ArrayList.c
*
* DESCRIPTION :
*       Implementation of an ArrayList
*
* AUTHOR :    Saher Anwar Ziauddin
* Source: My implementation of ArrayList from previous course:
*         https://git.cs.dal.ca/courses/2023-winter/csci-2122/lab5/ziauddin.git
*H*/

#include "ArrayList.h"

ArrayList* alist_initialize(int maxSize, int itemByteSize, char* datatype){
    ArrayList *arrayList = calloc(1, sizeof(ArrayList));
    arrayList->currSize = 0;
    arrayList->maxSize = maxSize;
    arrayList->itemByteSize = itemByteSize;
    arrayList->datatype = calloc(1, sizeof(char*));

    memcpy(arrayList->datatype, datatype, sizeof(char*));

    arrayList->arr = calloc(maxSize, sizeof(void*));

    return arrayList;
}

// TODO: What would cause this function to return false?
bool alist_add(ArrayList* arrayList, void* item){
    if(item == NULL){
        printf("Invalid item passed in\n");
        return false;
    }

    if(arrayList == NULL){
        printf("NULL arraylist passed in\n");
        return false;
    }

    // if arraylist still has space, add the item
    if(arrayList->currSize < arrayList->maxSize){
        arrayList->arr[arrayList->currSize] = calloc(1, arrayList->itemByteSize);
        memcpy(arrayList->arr[arrayList->currSize], item, arrayList->itemByteSize);
        arrayList->currSize++;

        // Test code:
        // printf("%d\n", *(int*)arrayList->arr[arrayList->currSize-1]);
        return true;
    } else{
        // resize the arraylist and add it
        printf("Resizing...\n");
        bool resizeSuccess = alist_resize(arrayList);
        if(!resizeSuccess){ return false;}

        arrayList->arr[arrayList->currSize] = calloc(1, arrayList->itemByteSize);
        memcpy(arrayList->arr[arrayList->currSize], item, arrayList->itemByteSize);
        arrayList->currSize++;

        return true;
    }
}

bool alist_add_at(ArrayList* arrayList, int index, void* item){
    if(arrayList == NULL){
        printf("Null arraylist passed in\n");
        return false;
    }

    if(index < 0 || index >= arrayList->currSize){
        printf("Invalid index\n");
        return false;
    }

    if(item == NULL){
        printf("Invalid item passed in\n");
        return false;
    }

    if(arrayList->currSize + 1 >= arrayList->maxSize){
        // resize
        printf("Resizing (add at)..\n");
        bool resizingSuccess = alist_resize(arrayList);
        if(!resizingSuccess){
            printf("Resizing failed\n");
            return false;
        }
    }

    // go in reverse
    arrayList->arr[arrayList->currSize] = calloc(1, arrayList->itemByteSize);
    for(int i = arrayList->currSize; i > index; i--){
        memcpy(arrayList->arr[i], arrayList->arr[i - 1], arrayList->itemByteSize);
    }
    memcpy(arrayList->arr[index], item, arrayList->itemByteSize);

    arrayList->currSize++;
    return true;
}

void alist_clear(ArrayList* arrayList){
    printf("Clearing arraylist\n");
    if(arrayList == NULL){
        return;
    }

    for(int i = 0; i < arrayList->currSize; i++){
        free(arrayList->arr[i]);
    }
    arrayList->currSize = 0;
}

void* alist_get(ArrayList* arr, int index){
    if(arr == NULL){
        return NULL;
    }
    if(index < 0 || index >= arr->currSize){
        return NULL;
    }

    return arr->arr[index];
}

int alist_index_of(ArrayList* arr, void* item){
    if(arr == NULL){
        return -1;
    }

    for(int i = 0; i < arr->currSize; i++){
        if(memcmp(arr->arr[i], item, arr->itemByteSize) == 0){
            return i;
        }
    }

    return -1;
}

// TODO: Feels like I should use realloc instead of calloc here
void* alist_remove(ArrayList* arr, int index){

    if(arr == NULL){
        return NULL;
    }

    if(index < 0 || index >= arr->currSize){
        return NULL;
    }

    // create a new pointer so that we can free the pointer in the array
    void *removedItem = calloc(1, arr->itemByteSize);

    // removing the element
    memcpy(removedItem, arr->arr[index], arr->itemByteSize);
    arr->arr[index] = calloc(1, arr->itemByteSize);

    // moving all elements to the left
    for(int i = index; i < arr->currSize - 1; i++){
        memcpy(arr->arr[i], arr->arr[i + 1], arr->itemByteSize);
        arr->arr[i + 1] = calloc(1, arr->itemByteSize);
    }

    // freeing the ptr
    free(arr->arr[arr->currSize-1]);

    // reducing the size by 1
    arr->currSize -= 1;

    return removedItem;
}

bool alist_destroy(ArrayList* arrayList){
    printf("Destroying arraylist\n");
    if(arrayList == NULL){
        return false;
    }

    for(int i = 0; i < arrayList->currSize; i++){
        free(arrayList->arr[i]);
    }

    free(arrayList->arr);
    free(arrayList->datatype);
    free(arrayList);

    return true;
}

bool alist_resize(ArrayList* arrayList){
    if(arrayList == NULL){
        return false;
    }
    arrayList->arr = realloc(arrayList->arr, arrayList->maxSize * sizeof(void*) * 2);

    if(arrayList->arr == NULL){
        return false;
    }

    arrayList->maxSize *= 2;
    return true;
}

void alist_print(ArrayList* arrayList){
    printf("ArrayList contents:\n");

    for(int i = 0; i < arrayList->currSize; i++){
        printf("%d ", *(int*)arrayList->arr[i]);
    }

    printf("\n");
}
