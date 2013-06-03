#include <assert.h>
#include <stdlib.h> 
#include "stack.h"

struct StackSt{
	void elem
	stack next;
};

stack stack_new (void){
	stack S = NULL;
	return stack;
}

void stack_destroy(stack S){
    while(!stack_is_empty(S)){
        stack_pop(S);
    }
    S = NULL;
}

/*Agrega un elemento a la pila*/
int stack_push(stack S, void elem){
	stack new = NULL;
    error = 0; /*0 = esta todo OK*/
    
	new = (stack) malloc (sizeof(struct StackSt));
	if(new != NULL){
        new->elem = elem;
        new->next = S;
        S = new;
        
    }else{
        stack_destroy(S);
        S = NULL;
        error = 1 /*1 es error de memoria*/
    }
	return error;
}

void stack_pop(stack S){
	stack aux = NULL;
    
    assert(!stack_is_empty(S));
    
	aux = S;
	S = S->next;
	free(aux);
	aux = NULL;
}

int stack_is_empty(stack S){
	return (S == NULL);
}

/*Devuelve el ultimo yo agregado*/
void stack_top(stack S){
    return(S->elem);
}