#include "alpha.h"
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*#define MinPQSize (10)*/
#define MinData (-32767)

struct HeapStruct {
    int Capacity;/*Largo actual*/
    int Size;/*Largo maximo*/
    ElementType *Elements;
};

heap Initialize(int MaxElements) {
    heap H;
	/*
    *if (MaxElements < MinPQSize){
    *    Error("Priority queue size is too small");
	*}*/
	H = malloc(sizeof ( struct HeapStruct));
	if (H == NULL){
		printf("Out of space!!!");
		exit(1);
	}
	
    /* Allocate the array plus one extra for sentinel*/
    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
	if (H->Elements == NULL){
		printf("Out of space!!!");
		exit(1);
	}
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[ 0 ] = MinData;

    return H;
}

void MakeEmpty(heap H) {
    H->Size = 0;
}

/* H->Element[ 0 ] is a sentinel */

heap Insert(ElementType X, heap H) {
    int i;

    if (IsFull(H)) {
        printf("Priority queue is full");
        exit(1);
    }

    for (i = ++H->Size; H->Elements[ i / 2 ] > X; i /= 2){
        H->Elements[ i ] = H->Elements[ i / 2 ];
	}
    H->Elements[ i ] = X;
	
	return H;
}

ElementType DeleteMin(heap H) {
    int i, Child;
    ElementType MinElement, LastElement;

    if (IsEmpty(H)) {
        printf("Priority queue is empty");
        return H->Elements[ 0 ];
    }
    MinElement = H->Elements[ 1 ];
    LastElement = H->Elements[ H->Size-- ];

    for (i = 1; i * 2 <= H->Size; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[ Child + 1 ]< H->Elements[ Child ]){
           Child++;
		}
        /* Percolate one level */
        if (LastElement > H->Elements[ Child ]){
            H->Elements[ i ] = H->Elements[ Child ];
		}else{
            break;
		}
    }
    H->Elements[ i ] = LastElement;
    return MinElement;
}

ElementType FindMin(heap H) {
    if (IsEmpty(H)){
		printf("Heap is empty");
		return H->Elements[ 0 ];
	}
    return H->Elements[ 1 ];
}

bool IsEmpty(heap H) {
    return H->Size == 0;
}

bool IsFull(heap H) {
    return H->Size == H->Capacity;
}

heap Destroy(heap H) {
    free(H->Elements);
	H->Elements = NULL;
    free(H);
	H = NULL;
	return H;
}

#if 0

for (i = N / 2; i > 0; i--)
    PercolateDown(i);

#endif
