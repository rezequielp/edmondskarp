#ifndef STACK_H
#define STACK_H

typedef struct StackSt *stack;


stack stack_new (void);
/*Pila vacia*/

void stack_destroy(stack p);
/*Destuctor de pila*/

int stack_push(stack p, void elem);
/*Agrega un elemento*/

void stack_pop(stack p);
/*Elimina el ultimo elemento agregado*/

int stack_is_empty(stack p);
/*Consulta si la pila es vacia o no*/

void stack_top(stack p);
/*Muestra el ultimo elemento agregado a la pila*/