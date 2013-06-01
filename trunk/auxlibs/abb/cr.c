#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "cr.h"
#include "error.h"


struct scr {
  FILE * f;
  bool isStdIn;
  Tuple el; /* fin(c) == (c->el = NULL) */
  bool arr;
};

void readWhites(FILE *f);

Tuple
tuple_fromStream(FILE * f);

char * 
readUntilDelim(FILE * f, const char del, ssize_t *len);

cr
cr_create(const char * f){
  cr c;

  assert(f != NULL);

  c = NULL;

  c = (cr) malloc(sizeof(struct scr));

  if (c != NULL){

    c->el = NULL;

    c->arr = false;

    if (f[0] == '\0'){
      warnx("cr_create use stdin"); 
      c->isStdIn = true;
      c->f = stdin;
    } else {
      c->isStdIn = false;
      c->f = fopen (f, "r");
    }    
    if (c->f == NULL){
      warn(ERRFMT,"cr_create",__LINE__);
      free(c);
      c = NULL;

    }
  }

  return c;
}

cr
cr_destroy(cr c){

  assert(c != NULL);
  assert(c->f != NULL);

  if (! c->isStdIn)
    fclose(c->f);

  c->f = NULL;

  if (c->el != NULL) 
    c->el = tuple_destroy(c-> el);
  

  free(c);
  c = NULL;
  
  return c;
}

void
cr_arr(cr c){
  assert(c != NULL);
  assert(c->f != NULL);
  assert(!c->arr);
  assert(c->el == NULL);

  c->arr = true;

  readWhites(c->f);

  if (feof(c->f))
    c->el = NULL;
  else 
    c->el = tuple_fromStream(c->f);
}

void
cr_av(cr c){
  assert(c != NULL);
  assert(c->f != NULL);
  assert(c->arr);
  assert(c->el != NULL);

  c->el = tuple_destroy(c->el);

  readWhites(c->f);

  if (feof(c->f))
    c->el = NULL;
  else 
    c->el = tuple_fromStream(c->f);
}

Tuple
cr_elec(const cr c){
  assert(c != NULL);
  assert(c->f != NULL);
  assert(c->arr);
  assert(c->el != NULL);
  
  return tuple_clone(c->el);
}

bool
cr_fin(const cr c){
  assert(c != NULL);
  assert(c->f != NULL);
  assert(c->arr);
  
  return (c->el == NULL);
}


void readWhites(FILE *f){
  fscanf(f,"%*[ \t\n]");
}

char *
readUntilDelim(FILE * f, const char del, ssize_t *len){
  size_t aux;
  char * res;

  res = NULL;
  aux = 0;
  *len = getdelim (&res, &aux, del, f);

  if (*len > 0 && 
      (res[*len - 1] == del || feof(f))){
    if (res[*len - 1] == del) {
      *len = *len - 1;
      res[*len] = '\0';
    }
  } else {
    if (aux > 0)
      free(res);
    res = NULL;
    *len = 0;
  }

  return res;
}

Tuple
tuple_fromStream(FILE * f){
/*
DESC: Constructor. Lee un Tuple o desde un stream.
      Devuelve NULL si no hay memoria o hubo error de archivo
      (error de hardware o parseo).
PRE: { e = NULL /\ f -> F }
  e = tuple_fromStream(f);
POS: {  Hay memoria /\ ! Error de Archivo ==>  e --> fromStream(F)
      ! Hay memoria \/  Error de Archivo  ==>  e = NULL  }
*/

  char *fst, *snd;
  ssize_t len;
  Tuple ret;

  static int lineNum = 0;

  assert(f != NULL);

  lineNum = lineNum + 1;

  fst = readUntilDelim(f, (char) ':', &len);

  if (fst != NULL){

    if (len > key_maxLen())
      /* El tamano de la clave es mayor que el maximo permitido */
      errx(EXIT_FAILURE, ERRFMT,"tuple_fromStream, error parseo, segundo campo",lineNum);
      

    snd = readUntilDelim(f, '\n', &len);

    if (snd == NULL) /* (error parseo) */
      errx(EXIT_FAILURE, ERRFMT,"tuple_fromStream, error parseo, segundo campo",lineNum);

  } else  /* fst == NULL (error parseo) */
    errx(EXIT_FAILURE, ERRFMT,"tuple_fromStream, error parseo, segundo campo",lineNum);
  
  ret = tuple_fromKeyData(key_fromString(fst), data_fromString(snd));

  free(fst);
  free(snd);

  return ret;

}


