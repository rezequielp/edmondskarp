#ifndef QUEUE_H
#define QUEUE_H

typedef struct queueSt *queue;


queue queue_new (void);
/* 
 * Crea una cola vacia
*/

queue queue_enqueue(queue Q, void elem);
/* 
 * Agrega un elemento de tipo alpha con el nuevo elemento agregado
 * Devuelve la misma cola con el elemento nuevo agregado
*/

queue queue_dequeue (queue Q);
/*
 * Elimina el primer elemento que entro a la cola
 * PRE: Q != vacio
*/

void queue_head (queue Q);
/* 
 *Funcion que muestra el primer elemento que entro a la cola
*/

int queue_is_empty (queue Q);
/* 
 *Funcion que devuelve true o false si la cola es vacia o no respectivamente
*/

queue queue_destroy (queue Q);
/* 
 * Libera toda la memoria asignada a Q
*/

u32 queue_length (queue Q);
/* 
 *Devuelve el largo de la cola
*/

#endif