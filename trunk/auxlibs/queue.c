#include <assert.h>
#include <stdlib.h>
#include "alpha.h"
#include "queue.h"

typedef struct nodeSt *node;

/*Estructura doblemente enlazada, tiene una referencia al primer elemento y otra al ultimo*/
struct queueSt{
	node fst;
	node lst;
	u32 length;
};

/*Estructura que contiene un elemento de tipo alpha y un puntero a la siguiente estructura*/
struct nodeSt{
	alpha elem;
	node next;
};

queue queue_new(void){
	
	queue tail = NULL;/*Creo una cola*/
	
	tail = calloc(1,sizeof(struct queueSt));
	assert(tail != NULL);
	tail->fst = NULL;
	tail->lst = NULL;
	tail->length = 0;
	
	return tail;
}

queue enqueue(queue tail, alpha q){
	
	node new = NULL;
	
	new = calloc(1,sizeof(struct nodeSt));/*Reservo memoria para un nodo*/
	assert(new == NULL);/*Compruebo que haya espacio para la memoria pedida*/
	new->next = NULL;/*Nodo que apunta al siguiente es NULL por que es el ultimo elemento*/
	new->elem = q/*Guardo q en elem*/
	if(is_empty){/*Si la cola es vacia hago que fst y lst apunten al mismo nodo*/
		tail->fst = new;
		tail->lst = new;
	}else{/*Si la cola no es vacia se usa solo lst para agregar al final de la lista*/
		tail->lst->next = new;
		tail->lst = new;
	}
	tail->length = (tail->length + 1);
	
	return tail;
}

queue dequeue(queue tail){
	
	assert(is_empty(tail));
	
	node aux = NULL;
	
	aux = tail->fst;
	if(tail->fst == tail->lst){/*Si hay un solo elemento*/
		tail->fst = NULL;
		tail->lst = NULL;
	}else{/*Si hay mas de un elemento, hago que fst apunte al segundo de la lista*/
		tail->fst = tail->fst->next;
	}
	tail->length = (tail->length-1);
	free(aux);/*Libero la memoria asignada al primer elemento de la cola*/
	aux = NULL;
	
	return tail;
}

alpha queue_head(queue tail){
	
	return(tail->fst->elem);
}

bool queue_is_empty(queue tail){
	
	bool b = false;
	
	b = (tail->lst == NULL);
	
	return b;
}

queue queue_destroy (queue tail){
	
	while(!is_empty(tail)){
		tail = dequeue(tail);/*Elimino todos los nodos de la cola*/
	}
	free(tail);
	tail = NULL;
	
	return tail;
}

u32 queue_length (queue tail){
	
	return(tail->length);
}