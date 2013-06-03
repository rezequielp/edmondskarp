#include <assert.h>
#include <stdlib.h> 
#include "Stack.h"

struct StackSt{
	Element *top;
	int size;
};

/* Estructura que contiene un elemento y un puntero a la siguiente estructura */
typedef struct ElementSt{
    void elem;
    Element *next;
}Element;


Stack stack_create (void){
	Stack S = NULL;
    S = (Stack) malloc(sizeof(struct StackSt));
    if (S != NULL){
        S->top = NULL;
        S->size = 0;
    }
	return S;
}

void stack_destroy(Stack S){
    while(!stack_isEmpty(S)){
        stack_pop(S);
    }
    S = NULL;
}

int stack_push(Stack S, void elem){
	Element *new = NULL;
    result = 0; /*0 = esta todo OK*/
    
	new = (Element *) malloc (sizeof(struct ElementSt));
	if(new != NULL){
        new->elem = s;
        new->next = NULL;
        S->top = new;
        S->size += 1;
    }else{
        stack_destroy(S);
        S = NULL;
        result = 1 /*1 es error de memoria*/
    }
	return result;
}

void stack_pop(Stack S){
	Element *aux = NULL;
    
    assert(!stack_isEmpty(S));
    
	aux = S->top;
	S->top = S->top->next;
    S->size -= 1; 
	free(aux);
	aux = NULL;
}

int stack_isEmpty(Stack S){
	return (S->size == 0);
}

void stack_top(Stack S){
    return(S->top->elem);
}

int stack_size(Stack S){
    return (S->size);
}

int stack_revert(Stack S1, Stack S2 ){
    Element *aux = NULL;
    int result = 1;
    
    assert((S1 != NULL) && (S2 != NULL));
    assert(stack_isEmpty(S2))

    aux = stack_top(S1);
    while ((stack_size(S1) != stack_size(S2)) && (result != 0)){
        result = stack_push(S2, aux);
        aux = aux->next;
    }
    return result;
}