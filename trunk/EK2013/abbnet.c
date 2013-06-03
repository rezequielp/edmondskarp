/*NECESITO EL TIPO QUEUE PARA HACER LA ELIMINACION DE ELEMENTOS NO RECURSIVA POR EL LIMITE DE RECURCION*/
#define Leaf ((Tree) NULL)

/* Estructura de un nodo por forward*/
typedef struct FNodeSt{
    u32 y;      /* El nodo forward de 'x'*/
    u64 flow;   /* El flujo por forward que se esta enviando*/
    u64 cap;    /* La capacidad restante de envio de flujo*/
}FNode;

/* Estructura de un nodo por backward*/
typedef struct BNodeSt{
    Node * y;    /* Puntero a la direccion de memoria del nodo 'y' en el arbol*/
}BNode;

/* Estructura de un nodo*/
typedef struct edgeNodeSt{
    u32 x;          /* El nodo en cuestion*/
    FNode *FArr;    /* Los nodos vecinos por forward*/
    BNode *BArr;    /* Los nodos vecinos por backward*/
    u32 FArrlength; /* Largo del arreglo de nodos por forward*/
    u32 BArrlength; /* Largo del arreglo de nodos por backrward*/
}edgeNode;

typedef struct networkNodeSt{
	edgeNode * edge;
	left * networkNode
	rigth * networkNode
}networkNode;

/* El arbol de nodos*/
struct AbbNetSt{ 
	int cant; /*cantidad de nodos en el arbol*/
	networkNode * tree; /*puntero a la copa del arbol*/
	Stack freeSpot /*recorrido la copa hasta la ubicacion para agregar un elemento*/
}AbbNet; /*TODO chequear los nombres de la structura con lo que dice en el .h*/

/*FUNCIONES ESTATICAS*/
static void network_adjust(Abbnet net);
static void network_newFreeSpot(AbbNet net);


/*
*			Herramientas para trabajar con AbbNet
*/

/*crea un AbbNet vacio*/
AbbNet network_create(){
	AbbNet net;
	net= (AbbNet)malloc(sizeof(AbbNetSt));
	return net;
}


/*Destruye un arbol y libera toda la memoria de sus elementos*/
void network_destroy(AbbNet net){
	networkNode * pivote;
	QUEUE = elem_list;
	elem_list = QUEUE_CREATE();
	QUEUE_ADD(elem_list, net->tree);/*mete la copa del arbol en la cola*/
	while(!QUEUE_IS_EMPTY(elem_list)){
		pivote = QUEUE_HEAD(elem_list);
		/*mete a los hijos de pivote a la cola si no son hojas*/
		if (pivote.left != Leaf)
			QUEUE_ADD(pivote.left);
		if (pivote.rigth != Leaf)
			QUEUE_ADD(pivote.rigth);
		/*elimina pivote*/
		EDGENODE_DESTROY(pivote);
		QUEUE_POP(elem_list);
		net->cant -= 1;
	}
}


/*Agrega el nodo al arbol*/
void network_add(AbbNet net, Node node){
	STACK_CURRENT(net->freeSpot) = & node;
	net->cant+=1;
	STACK_POP(net->freeSpot);
	/*Buscar el camino al nuevo freeSpot*/
	network_adjust(net);
	network_newFreeSpot(net);
}



/*Chequea si el net esta vacio. Retorna false si tiene elementos y true si esta vacio.*/
bool network_is_empty(AbbNet net){

}


/*busca el elemento key en el arbol y devuelve un puntero al nodo que machea ese key*/
Node network_search(AbbNet net, u32 key){

}


/*Elimina el elemento key del arbol y libera la memoria del nodo*/
void network_delete(AbbNet net, u32 key){

}

/*Acomoda el nodo en net->freeSpot para que el arbol sea un arbol de busqueda*/
/*Este nodo no necesariamente esta bien ubicado*/
void network_adjust(Abbnet net){

}


/*
*			FUNCIONES ESTATICAS
*/
/*Busca y almacena en el arbol un nuevo camino a un spot libre*/
void network_newFreeSpot(AbbNet net){
	/*Precondicion: network_newFreeSpot() se tiene que llamar  despues de haber agregado un elemento*/
	networkNode * pivot;
	networkNode * ancestor;
	pivot = STACK_CURRENT(net->freeSpot);
	STACK_POP(net->freespot);
	assert(pivot->left == Leaf);
	if(pivote->right != Leaf){
		if(!STACK_IS_EMPTY(net->freeSpot)){
			ancestor = STACK_CURRENT(net->freeSpot);
			/*mientras el hijo derecho del ancestro es el pivote*/
			while(!STACK_IS_EMPTY(net->freeSpot) && NETWORKNODE_COMPARE(ancestor->right, pivot)){
				/*sigo subiendo en el arbol*/
				pivot = ancestor;
				STACK_POP(net->freespot);
				ancestor = STACK_CURRENT(net->freeSpot);
			}
			/*pude haber salido por que el stack esta vacion o porque ancestor->right != pivot */
			if(!STACK_IS_EMPTY(net->freeSpot) ){
				
			}else{/* not NETWORKNODE_COMPARE(ancestor->right, pivot) */
			
			}
		}
	}
}


 void network_adjust(Abbnet net){
 
 }