#ifndef DIC_H
#define DIC_H 

#include <stdbool.h>

typedef char *Word;
typedef char *Def;
typedef struct sDict * Dict;

/* Constructor
diccionario vacio.*/
Dict dict_empty (void);

/* Agrega palabra y definicion.
Pre: !dict_exists(d,w)
(devuelve error si esto no sucede).*/
void dict_add (Dict d, Word w, Def f);

/* Pregunta si la palabra esta en el diccionario. */
bool dict_exists (Dict d, Word w);

/* Devuelve la definicion de una palabra
almacenandola en memoria dinamica
(acordarse de liberarla cuando no se use).
Pre: dict_exists(d,w)
(devuelve error si esto no sucede).*/
Def dict_search (Dict d, Word w);

/* Remueve la palabra y la definicion del diccionario.
Pre: dict_exists(d,w)
(devuelve error si esto no sucede).*/
void dict_del (Dict d, Word w);

/* Imprime todos los pares (clave, valor) en el diccionario. */
void dict_pprint (Dict d);

/* Devuelve la cantidad de definiciones almacenadas.
La funcion es de orden constante. */
int dict_length (Dict d);

/* Destructor. */
Dict dict_destroy (Dict d);

/* Maxima cantidad de caracteres del tipo Word */
int word_maxlen(void);

Dict dict_fromFile(char *nomfile);

void dict_toFile(char *nomfile, Dict d);

void dict_randomize(Dict d);

#endif
