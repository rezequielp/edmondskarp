#ifndef _ABBNET_H
#define _ABBNET_H

/* Este TAD es un arbol binario de busqueda por nodos, para construir caminos
 * y encontrar los lados rapidamente para aumentar los flujos.
 */

typedef struct AbbNetSt * AbbNet
/*
* Arboles
*/


AbbNet network_create(void);/*Crea un AbbNet vacio*/
void network_destroy(edgeNode netNode);/*Destruye un arbol y libera toda la memoria de sus elementos*/
void network_add(AbbNet net, edgeNode node);/*Agrega el nodo al arbol*/
bool network_isEmpty(AbbNet net);/*Devuelve True si esta vacio False sino*/
edgeNode network_search(AbbNet net, u32 key);/*Busca el elemento key en el arbol y devuelve un puntero al edge que machea ese key*/
/*Elimina el elemento key del arbol y libera la memoria del nodo*/
/*void network_delete(AbbNet net, u32 key);*/ /*no necesario para el proyecto*/

#endif