
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
/*
typedef struct networkNodeSt{
	edgeNode * edge;
	networkNode * left;
	networkNode * rigth;
}networkNode;
*/
networkNode networkNode_create(){
	networkNode net;
	node = (networkNode) malloc (sizeof(networkNodeSt));
	node->left = Leaf;
	node->right = Leaf;
}

void networkNode_destroy(edgeNode netNode){
	edgeNode_destroy(netNode);
	free(netNode)
}
/*los nodos se setean una vez y el seteo no se cambia nunca*/
void networkNode_set(){
	
}
bool networkNode_compare(networkNode node1, networkNode node2){
	return(edge_getX(node1) == edge_getX(node2))
}
u32 node_getKey(networkNode node){
	return edge_getX(node->edge);
}

/* 
 *						FUNCIONES SOBRE edgeNodes
*/
void edgeNode_create(edgeNode edgeNd){

}
void edgeNode_destroy(edgeNode edgeNd){

}

u32 edge_getX(edgeNode edge){
	return edge->x;
}