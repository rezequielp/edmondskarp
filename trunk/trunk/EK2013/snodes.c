
/* Estructura de un nodo por forward*/
typedef struct FNodeSt{
    u32 y;      /* El nodo forward de 'x'*/
    u64 flow;   /* El flujo por forward que se esta enviando*/
    u64 cap;    /* La capacidad restante de envio de flujo*/
}FNode;

/* Estructura de un nodo por backward*/
typedef struct BNodeSt{
    Node *y;    /* Puntero a la direccion de memoria del nodo 'y' en el arbol*/
}BNode;

/* Estructura de un nodo*/
typedef struct NodeSt{
    u32 x;          /* El nodo en cuestion*/
    FNode *FArr;    /* Los nodos vecinos por forward*/
    BNode *BArr;    /* Los nodos vecinos por backward*/
    u32 FArrlength; /* Largo del arreglo de nodos por forward*/
    u32 BArrlength; /* Largo del arreglo de nodos por backrward*/
}Node;

/* El arbol de nodos*/
struct SNodesSt{
    Abb Tree;
};

