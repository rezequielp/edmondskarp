#ifndef QUEUE_H
#define QUEUE_H

#include "alpha.h"

typedef struct queueSt *queue;

typedef unsigned int u32;

/*Crea una cola vacia*/
queue queue_new (void);

/*Agrega un elemento de tipo alpha con el nuevo elemento agregado
 *Devuelve la misma cola con el elemento nuevo agregado
 */
queue enqueue(queue tail, alpha elem);

/*Elimina el primer elemento que entro a la cola
 *PRE: Q != vacio
 */
queue dequeue (queue tail);

/*Funcion que muestra el primer elemento que entro a la cola*/
alpha queue_head (queue tail);

/*Funcion que devuelve true o false si la cola es vacia o no respectivamente*/
bool queue_is_empty (queue tail);

/*Libera toda la memoria asignada a Q*/
queue queue_destroy (queue tail);

/*Devuelve el largo de la cola*/
u32 queue_length (queue tail);

#endif