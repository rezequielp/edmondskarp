#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cw.h"
#include "error.h"
#include "stdbool.h"


struct scw {
  FILE * f;
  bool isStdOut;
  bool arr;
};

bool
tuple_toStream(FILE *f, const Tuple e);


cw
cw_create(const char * f){
/*
DESC: Constructor. Toma el nombre de archivo.
      Si el archivo existe lo borra.
      Si es vacio toma la salida estandard.
      Devuelve NULL si no hay memoria.
PRE: { c = NULL /\ f -> F }
  c = cw_create(f);  
POS: {  Hay memoria ==>  c --> cw(F)   
      ! Hay memoria ==>  c = NULL  }   
*/
  cw c;

  assert(f != NULL);

  c = NULL;

  c = (cw) malloc(sizeof(struct scw));

  if (c != NULL){

    c->arr = false;

    if (f[0] == '\0'){
      warnx("cw_create use stdout"); 
      c->isStdOut = true;
      c->f = stdout;
    } else {
      c->isStdOut = false;
      c->f = fopen (f, "w");
    }    
    if (c->f == NULL){
      warn(ERRFMT,"cw_create",__LINE__);
      free(c);
      c = NULL;

    }
  }

  return c;
}

cw
cw_destroy(cw c){
/*
DESC: Destructor del tipo. c cambia.
PRE: { c --> C }
   c = cw_destroy(c);
POS: { Se destruye C /\ c == NULL }
*/
  assert(c != NULL);
  assert(c->f != NULL);

  if (! c->isStdOut)
    fclose(c->f);

  c->f = NULL;

  free(c);
  c = NULL;
  
  return c;
}

void
cw_arr(cw c){
  assert(c != NULL);
  assert(c->f != NULL);
  assert(!c->arr);
  c->arr = true;

}

void
cw_ins(cw c, Tuple e){
  assert(c != NULL);
  assert(c->f != NULL);
  assert(c->arr);
  assert(e != NULL);

  if (!tuple_toStream(c->f, e))
    errx(EXIT_FAILURE, ERRFMT,"cw_create",__LINE__);

}

bool
tuple_toStream(FILE *f, const Tuple e){
/*
DESC: Guarda el parStr en un stream. 
PRE: { e -> E /\ f -> F }
  b = parStr_toStream(f,e);  
POS: { ! Error de Archivo ==> b /\ f -> add(F,e) 
         Error de Archivo ==> !b }   
*/
  bool ret;
  char *fst, *snd;

  assert(f != NULL);
  assert(e != NULL);

  fst = (char *) calloc(key_maxLen()+1,sizeof(char));

  key_toString(tuple_fst(e),fst);

  snd = data_toString(tuple_snd(e));

  ret =  (fprintf(f,"%s:%s\n",fst,snd) >= 0);

  free(fst);
  free(snd);

  return ret;
  
}
