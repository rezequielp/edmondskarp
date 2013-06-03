#ifndef STACK_H
#define STACK_H

typedef struct StackSt *Stack;


Stack stack_create(void);
/*Pila vacia*/

void stack_destroy(Stack S);
/*Destuctor de pila*/

int stack_push(Stack S, void elem);
/*Agrega un elemento*/

void stack_pop(Stack S);
/*Elimina el ultimo elemento agregado*/

int stack_isEmpty(Stack S);
/*Consulta si la pila es vacia o no*/

void stack_top(Stack S);
/*Muestra el ultimo elemento agregado a la pila*/

int stack_size(Stack S);
/*Retorna la cantidad de elementos de la pila*/

int stack_revert (Stack S1, Stack S2 );
/*Devuelve en S2 la pila S1 revertida*/