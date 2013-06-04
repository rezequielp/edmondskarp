#include <assert.h>
#include <stdlib.h>
#include "Queue.h"

/* Estructura doblemente enlazada, tiene una referencia al primer elemento 
 * y otra al ultimo */
struct queueSt{
	Element *head;
    Element *tail;
	int size;
};

/* Estructura que contiene un elemento y un puntero a la siguiente estructura */
typedef struct ElementSt{
	void *elem;
	Element *next;
}Element;

Queue queue_create(void){
	
	Queue Q = NULL;
	
	Q = (Queue *) malloc (sizeof(struct queueSt));
	if (Q != NULL){
        Q->head = NULL;
        Q->tail = NULL;
        Q->size = 0;
    }
	return Q;
}

int queue_enqueue(Queue Q, void q){
	
	Element *new = NULL;
    int result = 1;
	
	new = (Element*) malloc (sizeof(struct ElementSt));
	if (new != NULL){
        new->elem = q;
        new->next = NULL;
        if(queue_is_empty(Q)){
            Q->head = new;
            Q->tail = Q->head;
        }else{
            Q->tail->next = new;
            Q->tail = new;
        }
        Q->size = (Q->size + 1);
        result = 0;
    }
	return result;
}

void *queue_dequeue(Queue Q){
	Element *aux = NULL;
	void * elem = NULL;
    assert(Q != NULL && queue_isEmpty(Q));
    
	aux = queue_head(Q);
	if(aux->next != NULL){
		Q->head = Q->head->next;
	}else{
        Q->head = NULL;
        Q->tail = NULL;
    }
    elem = aux->elem;
    free(aux);
	Q->size -= 1;
	return elem;
}

void queue_head(Queue Q){
	return(Q->head->elem);
}

int queue_isEmpty(Queue Q){
	return (Q->tail == NULL);
}

int queue_destroy (Queue Q, void *garbage){
    int result = -1;
    int i = 0;
    int qSize;
    void * elem;
    
    assert(Q != NULL);
    
    qSize = queue_size(Q);
    while(!queue_isEmpty(Q)){
        elem = queue_dequeue(Q);
        if(garbage != NULL){
            garbage[i] = elem;
        }
        i ++;
    }
    if(qSize == i){
        result = i;
        free(Q);
        Q = NULL;
    }
	return result;
}

int queue_size (Queue Q){
	return (Q->size);
}