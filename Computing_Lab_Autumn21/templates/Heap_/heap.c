#include "heap.h"

// Note : The functions are written considering 0 Based Indexing

Heap *newHeap(size_t element_size, int (*comparator)(void*, size_t, size_t)){
    Heap *h = MALLOC(Heap, 1);
    h->element_size = element_size;
    h->num_elements = 0;
    h->max_elements = _INIT_MAX_ELEMENTS_HEAP_;
    h->elements = malloc(element_size*h->max_elements);
    h->comparator = comparator;
    if (h->elements == NULL){
        printf("newHeap : Failed to allot heap memory when initialising");
        return NULL;
    }
    return h;
}

// Position Heap operations
size_t parent(Heap *h, size_t position){
    size_t value = (position - 1)/2;
    if (value >= 0 && h->num_elements != 0){
        return value;
    }
    else{
        // printf("Parent: parent is not Available, returning Root index\ns");
        return 0;
    }
    return 0;
}

size_t rightChild(Heap *h, size_t position){
    size_t value = (2*position) + 2;
    if (value > h->num_elements){
        // printf("RighChild : rightchild is not available\n");
    }
    return value;
}

size_t leftChild(Heap *h, size_t position){
    size_t value = (2*position) + 1;
    if (value > h->num_elements){
        // printf("LeftChild : leftchild is not available\n");
    }
    return value;
}

// Basic Functionalities
void swap(Heap *h, size_t i, size_t j){
    char *t = MALLOC(char, h->element_size);
    void *l1 = h->elements + (i*h->element_size);
    void *l2 = h->elements + (j*h->element_size);

    memcpy((void *)t, l1, h->element_size);
    memcpy(l1, l2, h->element_size);
    memcpy(l2, (void *)t, h->element_size);
    free(t);
}

void reduceHeap(Heap *h){
    h->max_elements = h->max_elements / 2;
    h->elements = realloc(h->elements,(h->element_size*h->max_elements));
    if (h->elements == NULL){
        printf("reduceHeap : Failed memory allocation with heap resizing.\n");
        exit(0);
    }
}

void growHeap(Heap *h){
    h->max_elements = h->max_elements * 2;
    h->elements = realloc(h->elements, (h->element_size*h->max_elements));
    if (h->elements == NULL){
        printf("growHeap : Failed memory allocation with heap resizing.\n");
        exit(0);
    }
}

void freeHeap(Heap *h){
    free(h->elements);
    free(h);
}

//minheap routines
void minHeapPullUp(Heap *h, size_t position){
    while((position > 0) && ((*(h->comparator))(h->elements, position, parent(h, position)) == 1)){
        swap(h, position, parent(h, position));
        position = parent(h, position);
    }
}

void minHeapPushDown(Heap *h, size_t position){
    size_t minPosition = position;
    size_t lc = leftChild(h, position);
    if( (lc < h->num_elements) && ((*(h->comparator))(h->elements, lc, minPosition) == 1) ){
        minPosition = lc;
    }
    size_t rc = rightChild(h, position);
    if( (rc < h->num_elements) && ((*(h->comparator))(h->elements, rc, minPosition) == 1) ){
        minPosition = rc;
    }
    if (minPosition != position){
        swap(h, minPosition, position);
        minHeapPushDown(h, minPosition);
    }
}

void minHeapInsert(Heap *h, const void *inputptr){
    // inputptr needs to already have been MALLOC'ed and initialised with the data
    // that is going to be copied there
    if (h->num_elements == h->max_elements){
        growHeap(h);
    }
    void *inputAddress = h->elements + (h->num_elements * h->element_size);
    memcpy(inputAddress, inputptr, h->element_size);
    h->num_elements += 1;
    minHeapPullUp(h, (h->num_elements)-1);
}

void extractMin(Heap *h, void *outputptr){
    // outputptr needs to already have been MALLOC'ed with the the size
    // that is going to be copied there
    if (h->num_elements <= (h->max_elements/4)) {
        reduceHeap(h);
    }
    memcpy(outputptr, h->elements, h->element_size);
    swap(h, 0, h->num_elements-1);
    h->num_elements -= 1;
    minHeapPushDown(h, 0);
}
