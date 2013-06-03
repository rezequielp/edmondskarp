#include "network_node.h"
#inlcude "../auxlibs/bstring/bstrlib.h"

/* Estructura de un nodo por forward*/
typedef struct FNodeSt{
    u32 y;      /* El nodo forward de 'x'*/
    u64 flow;   /* El flujo por forward que se esta enviando*/
    u64 cap;    /* La capacidad restante de envio de flujo*/
}FNode;

typedef struct fAbb * bAbb

/* Estructura de un nodo por backward*/
typedef struct BNodeSt{
    Node * y;    /* Puntero a la direccion de memoria del nodo 'y' en el arbol*/
}BNode;

/* Estructura de un nodo*/
typedef struct edgeNodeSt{
	u32 x;          /* El nodo en cuestion*/
	FNode *fArr;    	/* Los nodos vecinos por forward*/
	u32 fSize;			/*tamaño del arreglo fArr*/
	BNode *bArr;   	/* Los nodos vecinos por backward*/
	u32 bSize;		/*tamaño del arreglo bArr*/
}edgeNode;

typedef struct networkNodeSt{
	edgeNode * edge;
	networkNode * left;
	networkNode * rigth;
}networkNode;

/* 
 *						FUNCIONES SOBRE NODOS
*/

networkNode networkNode_create(){
	networkNode net;
	node = (networkNode) malloc (sizeof(networkNodeSt));
	node->edge = void edgeNode_create():
	node->left = Leaf;
	node->right = Leaf;
}

/*setea los valores del nodo*/

void networkNode_destroy(networkNode netNode){
	edgeNode_destroy(netNode->edge);
	free(netNode)
}

void networkNode_set(networkNode netNode, u32 x, u32 y, u32 cap){
	edgeNode_set(networkNode edge, u32 x, u32 y, u32 cap);
}

bool networkNode_compare(networkNode node1, networkNode node2){
	return(edge_getX(node1) == edge_getX(node2))
}


u32 networkNode_getKey(networkNode node){
	return edge_getX(node->edge);
}

/* 
 *						FUNCIONES SOBRE EDGES
*/
edgeNode edgeNode_create(){

}
void edgeNode_destroy(edgeNode edgeNd){

}

u32 edge_getX(edgeNode edge){
	return edge->x;
}