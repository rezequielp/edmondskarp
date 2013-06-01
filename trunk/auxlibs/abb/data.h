#ifndef DATA_H
#define DATA_H


typedef struct sData * Data;

/* Construye un dato a partir de un string
Se copia el contenido de s. */
Data data_fromString (char *s);

/* Convierte un dato en un string en memoria dinamica.
Se deberia liberarla cuando no se use. */
char * data_toString (Data d);

/* Devuelve la cantidad de caracteres en el string almacenado.
Esta funcion es de orden constante. */
int data_lenght (Data d);

/* Devuelve un copia del dato
(en nueva memoria). */
Data data_clone (Data d);

/* Destructor.
Destruye todo el contenido */
Data data_destroy(Data d);

#endif

