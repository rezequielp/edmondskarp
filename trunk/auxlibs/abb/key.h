#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif


#ifndef KEY_H
#define KEY_H

#include <stdbool.h>

typedef struct sKey *Key;

/* Devuelve el tama~no maximo
(definido por KEY_MAX_LENGH en el \verb|.c|). */
int key_maxLen (void);

/* Construye un clave desde un string.
Se copia el contenido de s.
Pre: strlen(s) <= que key_maxLen()
(devuelve error si esto no sucede).*/
Key key_fromString (char *s);

/* Convierte una clave a string.
El tama~no de s debe ser >= key_length()+1. */
void key_toString (Key k, char *s);

/* Devuelve la longitud del string en k.
Esta funcion es de orden constante */
int key_length (Key k);

/* Pregunta si las claves son iguales. */
bool key_eq (Key k1, Key k2);

/* Pregunta si la primer clave es menor que la segunda. */
bool key_le (Key k1, Key k2);

/* Devuelve un copia (en nueva memoria). */
Key key_clone (Key k);

/* Destructor destruye todo el contenido */
Key key_destroy (Key k);

#endif

