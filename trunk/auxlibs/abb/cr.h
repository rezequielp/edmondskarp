#ifndef CR_H
#define CR_H

#include <stdbool.h>
#include "tuple.h"

typedef struct scr * cr;

cr
cr_create(const char * f);
/*
DESC: Constructor. Toma el nombre de archivo. 
      Si es vacio toma la entrada estandard 
      Devuelve NULL si no hay memoria o 
      hay algun problema con el archivo.
PRE: { f -> F }
  c = cr_create(f);  
POS: { Pi(c) ++ Pd(c) = F }   
*/

cr
cr_destroy(cr c);
/*
DESC: Destructor del tipo. c cambia.
PRE: { Pi(c) = F1 /\ Pd(c) = F2 /\ c --> C }
   c = cr_destroy(c);
POS: { F1 ++ F2 en disco /\ se destruye c /\ c == NULL }
*/

void
cr_arr(cr c);
/*
DESC: Arranca la cinta.
PRE: { F = Pi(c) ++ Pd(c) }
   cr_arr(c);
POS: { Pi(c)=[] /\ Pd(c)=F }
*/

bool
cr_fin(const cr c);
/*
DESC: Pregunta si llego al final.
PRE: { arrancada c }
PROP: cr_fin(c) == (Pd(c) = [])
*/

void
cr_av(cr c);
/*
DESC: Avanza la cinta.
PRE: { Pi(c) = F1 /\ Pd(c) = e:F2 }
   cr_av(c);
POS: { Pi(c)=F1:e /\ Pd(c)=F2 }
*/

Tuple
cr_elec(const cr c);
/*
DESC: Elemento corriente de la cinta. 
      Crea copia del elecor (hay que destruirlo despues).
PRE: { c-->C /\ Pi(C) = Pi /\ Pd(C) = e:Pd }
   el = cr_elecor(c);
POS: {  c->C /\
        Hay memoria ==> el -> e 
      ! Hay memoria ==> el = NULL}
*/


#endif /* CR_H */
