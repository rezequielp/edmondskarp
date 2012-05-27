#ifndef _EDGE_H
#define _EDGE_H

#include <stdbool.h>
#include "API.h"

#define FORWARD true
#define BACKWARD false
/*Las flag son del tipo bool, se usan los macros FORWARD y BACKWARD 
 *cuando el tipo de algo es una flag
*/
typedef struct bool flagSt;


/*la estructura del edge por lo pronto esta formada por 4 enteros u32 de manera
 *u32 x,u32 y, u32 cap,u32 flujo capaz se le agregue algo mas.
 *adArray esta formado por "array of edge"llamado edArray y un u32 counter
 *-el array of edge es un arreglo que tiene las aristas del network donde
 *el orden de los elementos esta dado por el orden en el cual se ingresaron.
 *-el counter representa la cantidad de aristas que se agregaron al network.
 *es muy importante no cambiar esto porque en el network hay un arreglo 
 *con indices de este arreglo, si se agrega un elemento en el medio del arreglo
 *de aristas se defasan los indices que le siguen y no anda nada
 */
typedef struct edArraySt edArray;
typedef struct edgeSt edge;

/*********************funciones sobre edArray***************************/
/*crea el edArray, devuelve un puntero a la estructura y NULL si falla*/
edArray *edArray_new();

/*destruye el edArray y las estructura que contiene*/
void edArray_destroy (edge *xy);

/**********************consulta edArray*****************************/
/*devuelve edarr->counter*/
u32 edArray_size(edArray *edarr);


/*devuelve el puntero al elemento i-esimo o NULL si falla*/
edge *edArray_item(edArray *edarr, u32 i);


/*devuelve true si esta vacio o false sino*/
bool edArray_is_empty(edArray *edarr);





/**********************funciones sobre edge***************************/
/*crea un edge. devuelve el puntero y un NULL si falla*/
/*esto es de la structura, no hay q pasarlo como parametro
 * en new solo se le da memoria y se inicializa en 0
 * (u32 x, u32 y, u32 cap, u32 flow)*/
edge *edge_new ();


/*destruye el edge*/
void edge_destroy(edge *xy);


/*añade un edge al final del arreglo, realloquea la memoria
 * y hace edarr->counter++.
*/
void *edge_add(EstadoNetwork net, edge *xy)


/*No se eligio retorno. capaz lo mejor sea un void.
 *assert: el (flujo a aumentar) <= (capacidad-flujo actual)
 *Aumenta el flujo del edge formado por los vertices "x" e "y"
 *NO HACER TODAVIA.FALTA DEFINIRLA.
*/
 edge_increase_flow (edge *xy, u32 flow);
 
/**********************consultas sobre edge***********************************/
/*toma como bool una contante de las siguientes que representa como se manda 
 *el flujo:
 *FORWARD constante que representa que el flujo se manda como forward.
 *BACKWARD constante que representa que el flujo se manda como backward.
 *devuelve true si el edge xy esta saturado en sentido FLAG. false sino lo esta.
*/
bool edge_saturated (edge *xy, flagSt FLAG );

#endif

