#ifndef TUPLA_H
#define TUPLA_H

#include "key.h"
#include "data.h"


typedef struct sTuple * Tuple;

/* Constructor.
No copia k d: almacena las referencias (punteros).*/
Tuple tuple_fromKeyData (Key k, Data d);

/* Devuelve una referencia (puntero) a la primer componente. */
Key tuple_fst (Tuple t);

/* Devuelve una referencia a la segunda componente. */
Data tuple_snd (Tuple t);

/* Devuelve un copia
(copia Key Data y Tuple en nueva memoria). */
Tuple tuple_clone (Tuple t);

/* Destructor.
Destruye la tupla con su Key y Data. */
Tuple tuple_destroy(Tuple t);


#endif
