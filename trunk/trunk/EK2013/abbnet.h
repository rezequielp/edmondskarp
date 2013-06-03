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
/*crea un arbol vacio, devuelve el puntero al arbol*/
AbbNet network_create();

/*Destruye un arbol y libera toda la memoria de sus elementos*/
void network_destroy(AbbNet net);

/*Agrega el nodo al arbol*/
void network_add(AbbNet net, Node node);

/*Chequea si el net esta vacio. Retorna false si tiene elementos y true si esta vacio.*/
bool network_is_empty(AbbNet net);

/*busca el elemento key en el arbol y devuelve un puntero al nodo que machea ese key*/
networkNode network_search(AbbNet net, u32 key);

/*Elimina el elemento key del arbol y libera la memoria del nodo*/
void network_delete(AbbNet net, u32 key);


#endif