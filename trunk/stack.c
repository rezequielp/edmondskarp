#include <assert.h>
#include <stdlib.h> 
#include "stack.h"

struct StackSt{
	unsigned int father;
	unsigned int son;
	stack next;
};

stack empty_stack(void){
	stack p = NULL;
	return stack;
}

/*Agrega una dupla (hijo,padre) a la pila*/
stack push(stack p, unsigned int son, unsigned int father){
	stack q = NULL;
	q = malloc(1,sizeof(struct StackSt));
	q->son = son;
	q->father = father;
	q->next = p;
	p = q;
	return p;
}

/*Elimina la ultima tupla agregada*/
stack pop(stack p){
	assert(!is_empty(p));
	stack q = NULL;
	q = p;
	p = p->next;
	free(q);
	q = NULL;
	return p;
}

/*Devuelve falso o verdadero si la pila es vacia o no*/
bool is_empty(stack p){
	bool b;
	b = (p == NULL);
	return b;
}

/*Devuelve el ultimo hijo agregado*/
unsigned int ultimate_push_fst(stack p){
	return(p->son);
}

/*Devuelve el ultimo padre agregado*/
unsigned int ultimate_push_snd(stack){
	return(p->father);
}