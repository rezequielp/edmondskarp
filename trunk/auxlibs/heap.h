#ifndef _HEAP_H
#define _HEAP_H
#include <stdbool.h>
#include "alpha.h"

typedef alpha ElementType;
typedef struct HeapStruct *heap;

/*Inicializa el heap
 MaxElements es para ver cuantos elementos se pueden agragar como maximo*/
heap Initialize(int MaxElements);

/*Destruye y libera la memoria*/
heap Destroy(heap H);

/*Crea heap vacio*/
void MakeEmpty(heap H);

/*Agrega un elemento nuevo de tipo alpha*/
heap Insert(ElementType X, heap H);

/*Elimina el elemento minimo*/
ElementType DeleteMin(heap H);

/*Busca el elemento minimo*/
ElementType FindMin(heap H);

/*Se fija si el heap es vacio*/
bool IsEmpty(heap H);

/*Se fija si el heap esta lleno*/
bool IsFull(heap H);

#endif