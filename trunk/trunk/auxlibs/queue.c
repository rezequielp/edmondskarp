#include <assert.h>
#include <stdlib.h>
#include "queue.h"

/* Estructura doblemente enlazada, tiene una referencia al primer elemento 
 * y otra al ultimo */
struct queueSt{
	Element *head;
    Element *tail;
	u32 length;
};

/* Estructura que contiene un elemento y un puntero a la siguiente estructura */
typedef struct ElementSt{
	void elem;
	Element *next;
}Element;

queue queue_new(void){
	
	queue Q = NULL;
	
	Q = (queue *) malloc (sizeof(struct queueSt));
	if (Q != NULL){
        Q->head = NULL;
        Q->tail = NULL;
        Q->length = 0;
    }
	return Q;
}

queue queue_enqueue(queue Q, void q){
	
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
        Q->length = (Q->length + 1);
    }
	return Q;
}

queue queue_dequeue(queue Q){
	
	assert(queue_is_empty(Q));
	
	Element *aux = NULL;
	
	aux = Q->head;
	if(Q->tail != NULL){
		Q->head = Q->head->next;
	}
	Q->length -= 1;
	free(aux);
	
	return Q;
}

void queue_head(queue Q){
	
	return(Q->head->elem);
}

int queue_is_empty(queue Q){
	
	return (Q->tail == NULL);
}

queue queue_destroy (queue Q){
	
	while(!queue_is_empty(Q)){
		Q = queue_dequeue(Q);
	}
	free(Q);
	Q = NULL;
	
	return Q;
}

u32 queue_length (queue Q){
	
	return (Q->length);
}