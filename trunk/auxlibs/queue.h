#ifndef QUEUE_H
#define QUEUE_H

typedef struct queueSt *Queue;


Queue queue_create (void);
/* 
 * Crea una cola vacia
*/

int queue_enqueue(Queue Q, void *elem);
/* 
 * Agrega un elemento de tipo alpha con el nuevo elemento agregado
 * Devuelve la misma cola con el elemento nuevo agregado
*/

void queue_dequeue (Queue Q);
/*
 * Elimina el primer elemento que entro a la cola
 * PRE: Q != vacio
*/

void *queue_head (Queue Q);
/* 
 *Funcion que muestra el primer elemento que entro a la cola
*/

int queue_isEmpty (Queue Q);
/* 
 *Funcion que devuelve true o false si la cola es vacia o no respectivamente
*/

void queue_destroy (Queue Q);
/* 
 * Libera toda la memoria asignada a Q
*/

int queue_size (Queue Q);
/* 
 *Devuelve el largo de la cola
*/

#endif