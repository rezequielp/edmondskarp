#include "network_node.h"
#include "abbnet.h"

#define Leaf ((networkNode) NULL)

/* El arbol de nodos*/
struct AbbNetSt{ 
	int cant; /*cantidad de nodos en el arbol*/
	networkNode * tree; /*puntero a la copa del arbol*/
	Stack freeSpot /*recorrido la copa hasta la ubicacion para agregar un elemento*/
}network; /*TODO chequear los nombres de la structura con lo que dice en el .h*/

/*FUNCIONES DEL MODULO*/
static void network_adjust(Abbnet net);
static void network_newFreeSpot(AbbNet net);


/*Crea un AbbNet vacio
*/
network network_create(){
	network net;
	net= (network)malloc(sizeof(AbbNetSt));
	return net;
}


/*Destruye un arbol y libera toda la memoria de sus elementos
*/
void network_destroy(AbbNet net){
	networkNode * pivote;
	QUEUE = elem_list;
	elem_list = QUEUE_CREATE();
	QUEUE_ADD(elem_list, net->tree);/*mete la copa del arbol en la cola*/
	while(!QUEUE_ISEMPTY(elem_list)){
		pivote = QUEUE_HEAD(elem_list);
		/*mete a los hijos de pivote a la cola si no son hojas*/
		if (pivote.left != Leaf)
			QUEUE_ADD(pivote.left);
		if (pivote.rigth != Leaf)
			QUEUE_ADD(pivote.rigth);
		/*elimina pivote*/
		edgeNode_destroy(pivote->edge);
		free(pivote);
		QUEUE_POP(elem_list);
		net->cant -= 1;
	}
}


/*Agrega el nodo al arbol
*/
void network_add(AbbNet net, u32 x, u32 y, u32 cap){
	networkNode netNodeF;
	networkNode netNodeB;
	/*agregar como forward*/
	netNode = networkNode_create();
	networkNode_setF(netNodeF, x, y, cap);
	net->cant+=1;
	/*Buscar el camino al nuevo freeSpot*/
	network_adjust(net);
	network_newFreeSpot(net);
	/*agregar como backward*/
	netNodeB = & network_search(net, y)
	networkNode_setB(netNodeB, x, y, cap)
	/*Buscar nuevamente el camino al nuevo freeSpot*/
	network_adjust(net);
	network_newFreeSpot(net);
}


/*Chequea si el net esta vacio. Retorna false si tiene elementos y true si esta vacio.
*/
bool network_isEmpty(AbbNet net){
	return (net->cant == 0)
}


/*Busca el elemento key en el arbol y devuelve un puntero al nodo que machea ese key
 *si existe, sino devuelve Leaf.*/
edgeNode network_search(AbbNet net, u32 key){   /*TODO*/
	networkNode pivot;
	bool found;
	pivot = net->tree;
	notFound = false
	while(pivot != Leaf)
	if(!node_compare(pivot, Leaf)){
		if(key < node_getKey(pivot)){
			pivot = pivot->left;
		}else if(node_getKey(pivot) < key){
			pivot = pivot->right;
		}
	}
	return pivot->edge;
}



/*Elimina el elemento key del arbol y libera la memoria del nodo.
*/
/* void network_delete(AbbNet net, u32 key){ NO IMPLEMENTADO

}
*/


/*Busca y almacena en el arbol un nuevo camino a un spot libre
*/
void network_newFreeSpot	(AbbNet net){
	/*Precondicion: network_newFreeSpot() se tiene que llamar  despues de haber agregado un elemento*/
	networkNode * pivot;
	networkNode * ancestor;
	pivot = STACK_TOP(net->freeSpot);
	STACK_POP(net->freespot);
	assert(pivot->left == Leaf);
	if(pivote->right != Leaf){
		if(!STACK_IS_EMPTY(net->freeSpot)){
			ancestor = STACK_TOP(net->freeSpot);
			/*mientras el hijo derecho del ancestro es el pivote*/
			while(networkNode_compare(ancestor->right, pivot) && STACK_SIZE(net->freeSpot) > 1 ){
				/*sigo subiendo en el arbol*/
				pivot = ancestor;
				STACK_POP(net->freespot);
				ancestor = STACK_TOP(net->freeSpot);
			}
			/*pude haber salido por que el stack esta vacion o porque ancestor->right != pivot 
			 * si sali por que el ancestro->right es diferente al pivote, entonces me voy por el
			 * el hijo derecho del ancestro todo a la izquierda.
			 * si sali porque llegue a la copa del arbol me voo todo a la izq a iniciar un nivel del arbol nuevo
			*/
			if(!networkNode_compare(ancestor->right, pivot){
				ancestro = ancestro->right;
			}
			while(ancestor->left != Leaf){
				STACK_ADD(net->freeSpot, ancestor);
				ancestor = ancestor->left;
			}
		}
	}
}


/*Acomoda el nodo en net->freeSpot para que el arbol sea un arbol de busqueda*/
/*Este nodo no necesariamente esta bien ubicado*/
 void network_adjust(Abbnet net){
 
 }
 
 