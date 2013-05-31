#include <assert.h>
#include <stdlib.h> 
#include "stack.h"

struct StackSt{
	u32 myself;
	u32 ancestor;
	stack next;
    /*agregar capacidad aca?*/
};

stack stack_new (void){
	stack p = NULL;
	return stack;
}

void stack_destroy(stack p){
    while(!stack_is_empty(p)){
        stack_pop(p);
    }
    p=NULL;
}

/*Agrega una tupla (myself, ancestor) a la pila*/
int stack_push(stack p, u32 myself, u32 ancestor){
	stack q = NULL;
    error = 0;/*0 = esta todo OK*/
	q = (stack)malloc(sizeof(struct StackSt));
	if(q != NULL){
        q->myself = myself;
        q->ancestor = ancestor;
        q->next = p;
        p = q;
        
    }else{
        stack_destroy(p);/*hay que escribirla*/
        p=NULL;
        err=1 /*1 es error de memoria*/
    }
	return err;
}

/*Elimina la ultima tupla agregada*/
void stack_pop(stack p){
	assert(!stack_is_empty(p));
	stack q = NULL;
	q = p;
	p = p->next;
	free(q);
	q = NULL;
}

/*Devuelve verdadero o falso si la pila es vacia o no respectivamente*/
bool stack_is_empty(stack p){
	return (p == NULL);
}

/*Devuelve el ultimo yo agregado*/
u32 stack_see_myself(stack p){
	return(p->myself);
}

/*Devuelve el ultimo ancestro agregado*/
u32 stack_see_ancestor(stack p){
	return(p->ancestor);
}