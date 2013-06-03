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
	void elem;
	Element *next;
}Element;

Queue queue_new(void){
	
	Queue Q = NULL;
	
	Q = (Queue *) malloc (sizeof(struct queueSt));
	if (Q != NULL){
        Q->head = NULL;
        Q->tail = NULL;
        Q->size = 0;
    }
	return Q;
}

Queue queue_enqueue(Queue Q, void q){
	
	Element *new = NULL;
	
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
    }
	return Q;
}

Queue queue_dequeue(Queue Q){
	
	assert(queue_is_empty(Q));
	
	Element *aux = NULL;
	
	aux = Q->head;
	if(Q->tail != NULL){
		Q->head = Q->head->next;
	}
	Q->size -= 1;
	free(aux);
	
	return Q;
}

void queue_head(Queue Q){
	
	return(Q->head->elem);
}

int queue_is_empty(Queue Q){
	
	return (Q->tail == NULL);
}

Queue queue_destroy (Queue Q){
	
	while(!queue_is_empty(Q)){
		Q = queue_dequeue(Q);
	}
	free(Q);
	Q = NULL;
	
	return Q;
}

int queue_size (Queue Q){	
    
	return (Q->size);
}