
/* Estructura de un nodo por forward*/
typedef struct fNodeSt fNode;

typedef struct fAbb * bAbb

/* Estructura de un nodo por backward*/
typedef struct bNodeSt bNode;

/* Estructura de un nodo*/
typedef struct edgeNodeSt edgeNode;

typedef struct networkNodeSt networkNode;



/*
 *						FUNCIONES SOBRE edgeNodes
*/
edgeNode edgeNode_create();
void edgeNode_destroy(edgeNode edgeNd);
void networkNode_set(networkNode netNode, u32 x, u32 y, u32 cap);
u32 edge_getX(edgeNode edge);