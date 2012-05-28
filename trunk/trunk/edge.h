#ifndef _EDGE_H
#define _EDGE_H

#include <stdbool.h>
#include "API.h"


/*Las flag son del tipo bool, se usan los macros FORWARD y BACKWARD
 *cuando el tipo de algo es una flag
*/
typedef bool flag_s;

#define FORWARD (flag_s) true
#define BACKWARD (flag_s) false


/*la estructura del edge por lo pronto esta formada por 4 enteros u32 de manera
 *u32 x,u32 y, u32 cap,u32 flujo capaz se le agregue algo mas.
 * (le agregue el tipo sense que indica para que sentido se envia el flujo)
 *adArray esta formado por "array of edge" llamado edArray y un u32 counter
 * -El edArray es un arreglo que tiene las aristas del network donde
 *   el orden de los elementos esta dado por el orden en el cual se ingresaron.
 * -El counter representa la cantidad de aristas que se agregaron al network.
 *es muy importante no cambiar esto porque en el network hay un arreglo 
 *con indices de este arreglo, si se agrega un elemento en el medio del arreglo
 *de aristas se defasan los indices que le siguen y no anda nada
 */
typedef struct edgeSt edge;
typedef struct edArraySt edArray;


/**********************funciones sobre edge***************************/

/* Crea un nuevo lado. Se le debe pasar los nombres de los nodos y la capacidad
 * El flujo se inicializa en 0
 * Si ocurrio un error, retorna NULL*/
edge *edge_new (u32 nod1, u32 nod2, u32 capacity);

/* Destruye el edge*/
void edge_destroy (edge *xy);

/*No se eligio retorno. capaz lo mejor sea un void.
 *assert: el (flujo a aumentar) <= (capacidad-flujo actual)
 *Aumenta el flujo del edge formado por los vertices "x" e "y"
 *NO HACER TODAVIA.FALTA DEFINIRLA.
*/
 edge_increase_flow (edge *xy, u32 flow);

/* Setea el sentido del edge en el que se va a correr flujo*/
void edge_set_sense (edge *xy, flag_s FLAG)


/**********************consultas sobre edge***********************************/

/* Devuelve el sentido del edge en el que se va a correr flujo*/
flag_s edge_get_sense (edge *xy);

/* Decide si el lado se encuentra saturado en el sentido consultado
 * Pre: edge != NULL y cap >= flow
 * Ret: true si el edge xy esta saturado en sentido FLAG. false sino lo esta.
*/
bool edge_saturated (edge *xy, flagSt FLAG );






/*********************funciones sobre edArray***************************/

/* Crea un edArray. Devuelve un puntero a la estructura
 * Si ocurrio un error, retorna NULL*/
edArray *edArray_new();

/* Destruye el edArray y las estructura que contiene*/
void edArray_destroy (edge *xy);

/* Añade un edge al final del arreglo*/
void *edArray_add_edge (edArray *edarr, edge *xy);

/**********************consulta edArray*****************************/

/* Devuelve la cantidad de elementos de edarr
 * Ret: edarr->counter*/
u32 edArray_size(edArray *edarr);


/* Devuelve un puntero al elemento i-esimo o NULL si falla
 * WARNING: El puntero devuelto no se debe liberar, el edge sigue siendo
 * parte de edarr
 */
edge *edArray_item(edArray *edarr, u32 i);


/* Devuelve true si esta vacio o false sino*/
bool edArray_is_empty(edArray *edarr);

#endif

