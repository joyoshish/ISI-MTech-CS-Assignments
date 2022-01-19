#ifndef _G_COMMON_H_
#define _G_COMMON_H_
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#endif

#ifndef _GHEAP_
#define _GHEAP_

#define _INIT_MAX_ELEMENTS_HEAP_ 128

typedef struct Heap{
    // Array Implementation
    void *elements;
    size_t element_size;
    // size of the type of element stored in the heap
    size_t num_elements;
    // total elements in the heap
    size_t max_elements;
    // maximum number of elemes at the heap can handle
    int (*comparator)(void*, size_t, size_t);
    //comparator function (for custom checking of which node is greater than the other)
    // first argument of comarator is the array
    // second argument is the first postion value in the array we need to compare
    // third argument is the second postion value in the array we need to compare
    // the comparator should return 1 if the value at the position give by second
    // argument is less than third argument else 0
} Heap;

Heap *newHeap(size_t element_size, int (*comparator)(void*, size_t, size_t));

// Position Heap operations
size_t parent(Heap *h, size_t position);
size_t rightChild(Heap *h, size_t position);
size_t leftChild(Heap *h, size_t position);

// Basic Functionalities
void swap(Heap *h, size_t i, size_t j);
void reduceHeap(Heap *h);
void growHeap(Heap *h);
void freeHeap(Heap *h);
// void removePositionFromHeap(Heap *h, size_t position);   // yet to implement

//minheap routines
void minHeapPullUp(Heap *h, size_t position);
void minHeapPushDown(Heap *h, size_t position);
void minHeapInsert(Heap *h, const void *inputptr);
void extractMin(Heap *h, void *outputptr);
// void minHeapify(Heap *h);       // yet to implement

//maxheap routines
// void maxHeapify(Heap *h);       // yet to implement
// void maxHeapInsert(Heap *h, const void *inputptr);
// void extractMax(Heap *h, void *outputptr);      // yet to implement
// void maxHeapPullUp(Heap *h, size_t position);       // yet to implement
// void maxHeapPushDown(Heap *h, size_t position);     // yet to implement

#endif  //_GHEAP_


#ifndef _G_MEMORY_ALLOCATION_H_
#define _G_MEMORY_ALLOCATION_H_
#define MALLOC(type, n) (type *)malloc(sizeof(type)*n)
#define CALLOC(type, n) (type *)calloc(sizeof(type), n)
#endif

#ifndef _G_COMPARISION_H_
#define _G_COMPARISION_H_
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif
