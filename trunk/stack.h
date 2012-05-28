#ifndef STACK_H
#define STACK_H

/*Esta pila toma 2 unsigned int por que lo necesitamos para ir guardando el padre y el hijo*/

typedef struct StackSt *stack;

/*Pila vacia*/
stack empty_stack(void);

/*Agrega una dupla (hijo,padre) a la pila*/
stack push(stack p, unsigned int son, unsigned int father);

/*Elimina la ultima tupla agregada*/
stack pop(stack p);

/*Devuelve falso o verdadero si la pila es vacia o no*/
bool is_empty(stack p);

/*Devuelve el ultimo hijo agregado*/
unsigned int ultimate_push_fst(stack p);

/*Devuelve el ultimo padre agregado*/
unsigned int ultimate_push_snd(stack p);