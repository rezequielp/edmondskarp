#ifndef _SNODE_H
#define _SNODE_H

/* Este TAD es un arbol binario de busqueda por nodos, para construir caminos
 * y encontrar los lados rapidamente para aumentar los flujos.
 * Contiene dos estructuras, la del arbol y la de los nodos.  Como el arbol no esta modularizado
 * para trabajar con cualquier tipo de nodo se decidio poner todo en el mismo archivo.
 */

typedef struct AbbNetSt * AbbNet
/*
* Arboles
*/

/*Crea un AbbNet vacio*/
AbbNet networkNode_create(void);


/*Destruye un arbol y libera toda la memoria de sus elementos*/
void networkNode_destroy(edgeNode netNode);


/*setea los valores del nodo*/
void networkNode_set(/*ver que pasar aca*/);


/*Agrega el nodo al arbol*/
void network_add(AbbNet net, Node node);


/*Devuelve True si esta vacio False sino*/
bool network_isEmpty(AbbNet net);


/*Busca el elemento key en el arbol y devuelve un puntero al nodo que machea ese key*/
networkNode network_search(AbbNet net, u32 key);


/*Elimina el elemento key del arbol y libera la memoria del nodo*/
/*void network_delete(AbbNet net, u32 key);*/ /*no necesario para el proyecto*/

#endif