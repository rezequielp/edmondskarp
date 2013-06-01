#ifndef CW_H
#define CW_H

#include "tuple.h"

typedef struct scw * cw;

cw
cw_create(const char * f);
/*
DESC: Constructor. Toma el nombre de archivo. 
      Si el archivo existe lo borra.
      Si es vacio toma la salida estandard.
      Devuelve NULL si no hay memoria o 
      hay algun problema con el archivo.
PRE: { f -> F }
  c = cw_create(f);  
POS: {  Pi(c) ++ Pd(c) = F' }   
*/

cw
cw_destroy(cw c);
/*
DESC: Destructor del tipo. c cambia.
PRE: { Pi(c) = F /\ Pd(c) = [] /\ c --> C }
   c = cw_destroy(c);
POS: { F en disco /\ se destruye C /\ c == NULL }
*/

void
cw_arr(cw c);
/*
DESC: Arranca la cinta.
PRE: { F = Pi(c) ++ Pd(c) }
   cw_arr(c);
POS: { Pi(c)=[] /\ Pd(c)=[] }
*/

void
cw_ins(cw c, Tuple e);
/*
DESC: Inserta un elemento al final.
PRE: { Pic(c) = Pi /\ Pd(c) = [] }
   c = cw_insert(c,e);
POS: {  Pi(c)=Pi:e /\ Pd(c)=[] }
*/

#endif /* CW_H */
