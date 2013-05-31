#ifndef STACK_H
#define STACK_H

/*Esta pila toma 2 u32 por que lo necesitamos para ir guardando 
 *myself y ancestor
*/

typedef struct StackSt *stack;
typedef unsigned int u32;

/*Pila vacia*/
stack stack_new (void);

void stack_destroy(stack p);

/*Agrega una dupla (myself, ancestor) a la pila*/
int stack_push(stack p, u32 myself, u32 ancestor);

/*Elimina la ultima tupla agregada*/
void stack_pop(stack p);

/*Devuelve falso o verdadero si la pila es vacia o no*/
bool stack_is_empty(stack p);

/*Devuelve el ultimo myself agregado*/
u32stack_see_myself(stack p);

/*Devuelve el ultimo ancestor agregado*/
u32 stack_see_ancestor(stack p);