#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**********************Heap Sort************************************
typedef struct
{
	size_t element_size; // Generic implementation 
	unsigned int num_allocated, num_used; // Keep track of the size
	void *array; // Using one-based indexing
	int (*comparator)(void *, int, int); // Returns -ve, 0, or +ve
}HEAP;

void swap(HEAP *h, int i, int j)
{
	// h->array[0] used as swapping variable in one-based indexing
	char *ip = (char *) h->array + i * h->element_size;
	char *jp = (char *) h->array + j * h->element_size;
	char *tp = (char *) h->array;
	// Memory to memory copy of the elements for swapping
	memcpy((void *) tp, (void *) ip, h->element_size);
	memcpy((void *) ip, (void *) jp, h->element_size);
	memcpy((void *) jp, (void *) tp, h->element_size);
	return;
}

static void swapDown(HEAP *h, int k)
{
	// Repeat until the left child (2k) is within the boundary
	while (2*k <= h->num_used)
	{
		int j = 2*k; // Left child (2k)
		// Choose the child with larger key
		if(j < h->num_used && (h->comparator(h->array, j, j+1) < 0))
			j++; 
		// Right child (larger key is at 2k+1)
		if(h->comparator(h->array, k, j) >= 0) // No swapping needed
			break;
		// Swap parent at position k with the largest child
		swap(h, k, j);k = j;
	}
	return;
}
void heapSort(void *a,int N, size_t element_size, int(*comparator)(void*,int,int)) 
{
	int k;
	HEAP h;
	h.element_size = element_size;
	h.num_allocated = h.num_used = N;
	h.array = a;
	h.comparator = comparator;

	//Build Heap
	for(k = N/2; k >= 1; k--)
		swapDown(&h, k);
	//repeated deletemax
	while(h.num_used > 1) 
	{
		swap(&h, 1, h.num_used);
		h.num_used--;
		swapDown(&h, 1);
	}
}

//*************************Insertion********************

void insertionSort(void *array, int N, size_t element_size, int (*compare)(void*,int,int))
{
	int i, j;
	for(i = 1; i<N; i++)
	{
		memcpy(array, array+i*element_size, element_size);

		for(j = i-1; j>=0 && compare(array, 0, j)<0; j--)
		{
			memcpy(array+(j+1)*element_size, array+j*element_size, element_size);
		}
		memcpy(array+(j+1)*element_size, array, element_size);

	}
}
//*************************Bubble***************************
void bubbleSort(void *array, int N, size_t element_size, int (*compare)(void*,int,int))
{
	int i, j;
	for(i = 1; i<N-1; i++)
	{
		for(j = 1; j<N-i; j++)
		{
			if(compare(array, j+1, j) < 0)
			{
				memcpy(array, array+j*element_size, element_size);
				memcpy(array+j*element_size, array+(j+1)*element_size, element_size);
				memcpy(array+(j+1)*element_size, array, element_size);
			}
		}
		
	}
}

//************************Merge Sort************************
void merge(void *array, int b, int m, int e, int (*compare)(void*,int,int), size_t element_size)
{
	int i, j, k, l;
	void *B = malloc((e-b+1)*element_size); //Auxiliary array B
	for(i=b, j=m+1, k=0; i<=m && j<=e;)
	{
		if(compare(array, i, j) < 0)
			memcpy(B+element_size*k++, array+element_size*i++, element_size);
		else if(compare(array, i, j) > 0)
			memcpy(B+element_size*k++, array+element_size*j++, element_size);
		else
		{
			memcpy(B+element_size*k++, array+element_size*i++, element_size);
			memcpy(B+element_size*k++, array+element_size*j++, element_size);
		}
	}
	if(i>m && j<=e)
		for(l = j;l<=e;l++)
			memcpy(B+element_size*k++, array+element_size*j++, element_size);
	else if(j>e && i <=m)
		for(l = i;l<=m;l++)
			memcpy(B+element_size*k++, array+element_size*i++, element_size);
	
	//Copy B to A
	for(i = b;i<=e;i++)
		memcpy(array+element_size*i, B+element_size*(i-b), element_size);
	free(B);
}

void msort(void *array, int begin, int end,int (*compare)(void*,int,int), size_t element_size)
{
	if(begin<end)
	{
		int middle = (begin + end)/2;
		msort(array, begin, middle, compare, element_size);
		msort(array, middle+1, end, compare, element_size);
		merge(array, begin, middle, end, compare, element_size);
	}
}

