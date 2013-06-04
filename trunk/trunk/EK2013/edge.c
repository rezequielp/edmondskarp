#include "network_node.h"
#include "../auxlibs/bstring/bstrlib.h"

/* Estructura de un nodo por forward*/
typedef struct FNodeSt{
    u32 y;      /* El nodo forward de 'x'*/
    u32 cap;    /* La capacidad restante de envio de flujo*/
    u32 flow;   /* El flujo por forward que se esta enviando*/
}FNode;

/* Estructura de un nodo por backward*/
typedef struct BNodeSt{
    FNode * y;    /* Puntero a la direccion de memoria del nodo 'y' en el arbol*/
}BNode;

/* Estructura de un nodo*/
struct edgeSt{
    u32 x;      /* El nodo en cuestion*/
    Abb *fAbb;  /* Los nodos vecinos por forward*/
    Abb *bAbb;  /* Los nodos vecinos por backward*/
};

Edge edge_create(u32 x){
    Edge edge;
    
    edge = (Edge)malloc(sizeof(struct EdgeSt));
    if(edge != NULL){
        edge->x = x;
        edge->fAbb = abb_create();
        edge->bAbb = abb_create();
    }
    return edge;
}

void edge_destroy(Edge edge){
    FNode * fNodes;
    
    assert(edge != NULL);
    
    fSize = abb_size(edge->fAbb);
    fNodes = (FNode) malloc(fSize * sizeof(struct FNodeSt));
    if(fNodes != NULL){
        fSize = abb_destroy(fAbb, fNodes);
    }
    while (fSize > 0){
        free(fNodes[fSize - 1]);
        fSize --;
    }
    abb_destroy(edge->bAbb, NULL);
    free(edge->bAbb);
    if (fSize == 0){
        free(edge->fAbb);
        free(edge);
        edge = NULL;
    }
    free(fNodes);
}

void edge_set(Edge xEdge, Edge yEdge, u32 cap){
    FNode yFNode; /*nodo 'y' como forward node de 'x' */
    BNode xBNode; /*nodo 'x' como backward node de 'y' */
    u32 x;
    u32 y;
    
    assert(xEdge != NULL);
    assert(yEdge != NULL);
    
    /*Agregado de forward en xEdge*/
    y = edge_getX(yEdge);
    yFNode = fNode_create(y, cap, 0);
    abb_add(xEdge->fAbb, y, yFNode);
    
    /*Agregado de backward en xEdge*/
    x = edge_getX(xEdge);
    xBNode = bNode_create(yEdge);
    abb_add(edge->bAbb, x, bNode);
}

 /*GETS/SETS*/
u32 edge_getX(Edge edge){
    assert(edge != NULL);
    return (edge->x);
}

void edge_setFlow(Edge edge, u32 y, u32 flow, int direction){
    Abb tree;
    FNode yNode;
    
    assert(edge != NULL);
    
    if(direction == FORWARD){
        yNode = abb_search(edge->fAbb, y);
    }else{
        yNode = *(abb_search(edge->bAbb, y));/*lo apuntado por*/
    }
    yNode->flow += flow * direction;
}

/*La capacidad solo se pide de lados forwards*/
u32 edge_getCap(Edge edge, u32 y){
    
    assert(edge != NULL)

    yNode = abb_search(edge->fAbb, y);
    return yNode->cap;
}

u32 edge_getFlow(Edge edge , u32 y, int direction){
    FNode yNode;
    
    assert(edge != NULL);
    
    if(direction == FORWARD){
        yNode = abb_search(edge->fAbb, y);
    }else{
        yNode = *(abb_search(edge->bAbb, y));/*lo apuntado por*/
    }
    return yNode->flow;
}


