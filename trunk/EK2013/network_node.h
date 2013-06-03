
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
void edgeNode_create(edgeNode edgeNd);
void edgeNode_destroy(edgeNode edgeNd);
void networkNode_set(/*ver que pasar aca*/);
u32 edge_getX(edgeNode edge);