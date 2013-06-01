#ifndef ABB_H
#define ABB_H

#include "key.h"
#include "data.h"
#include <stdbool.h>

typedef struct sAbb *Abb;
typedef struct Branch *Tree;

/* constructor */
Abb abb_empty (void);

/* agrega una clave y un dato */
void abb_add (Abb h, Key k, Data d);

/* devuelve si existe la clave en el abb */
bool abb_exists (Abb h, Key k);

/* busca un dato segun la clave
debe llamarse solo si abb_exists (l, k)
si no lo encuentra devuelve NULL */
Data abb_search (Abb h, Key k);

/* borra la clave y el valor asociado */
void abb_del (Abb h, Key k);

/* devuelve la cantidad de elementos */
int abb_length (Abb h);

/* Lee un abb desde un archivo*/
Abb abb_fromFile(char *nomfile);

/* Graba un abb a un archivo*/
void abb_toFile(char *nomfile, Abb h);

/* imprime todos los pares (Key, Data) en el arbol */
void abb_pprint (Abb l);

/* Destructor. Destruye todo el abb y su contenido */
Abb abb_destroy(Abb h);

void abb_randomize(Abb h);

#endif
