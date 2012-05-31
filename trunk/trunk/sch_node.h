/* Este TAD es el arreglo de busqueda por nodos, para construir caminos
 * y encontrar los edges rapidamente para aumentar los flujos.
 */
#ifndef _SEARCH_NODE_H
#define _SEARCH_NODE_H

#define SCHARR_OK 1
#define SCHARR_ERR 0
/* Estructuras del arreglo de busqueda por nodos*/
typedef struct schArraySt schArray;

/* Crea un nuevo arreglo de busqueda. Se inicializa la estructura
 * Si pudo alloquear memoria, devuelve un puntero al nuevo arreglo de busqueda
 * Si ocurrio error, devuelve un puntero a NULL*/
schArray *schArray_new ();

/* Destruye un schArray*/
void schArray_destroy (schArray *scharr);

/* Agrega un edge al arreglo de busqueda.
 * Del edge se obtienen los nodos, para la busqueda por nodos; y se almacena
 * un puntero a la memoria en donde se encuentra alojado el edge*/
int schArray_add_edge (schArray *scharr, edge *xy);


#endif