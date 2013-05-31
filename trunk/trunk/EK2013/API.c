#include <stdlib.h>
#include "constants.h"/*s=0, t=1*/

struct NetworkSt{
    u64 maxFlow; /*valor del flujo del network*/
    edgeArray edgeArr; /*Arreglo de (x, y, c) no ordenados*/
    sVertices * minCut; /*search vertice tree.corte*/
    sNodes * schNode;/*search node tree. busqueda con vecinos Fordward y Backwad*/
    u32 temp_cap;/*para saber la capacidad minima del camino actual*/
    int whereWeAre[3];/*[flujo maximal?, llego a t?, aumento flujo?]*/
};

DragonP dragon_rise(){
    DragonP dragon = NULL;
    dragon = (DragonP) malloc(sizeof(NetworkSt));
    if (dragon != NULL)){
            dragon->maxFlow = 0;
            dragon->minCut = stack_new();
            dragon->edgeArr = edgeArray_new();
            dragon->schNode = sNode_new();
            if (dragon->edgeArr == NULL || dragon->schNode == NULL){
                dragon_slayer(dragon);
                dragon = NULL;
            }
            dragon->whereWeAre = {0, 0, 0};
    }
    return dragon;
}

void dragon_slayer(dragonP dragon){
    assert(dragon != NULL);
    
    if (dragon->edgeArr != NULL){
        edgeArray_destroy(dragon->edgeArr);
        dragon->edgeArr = NULL;
    }
    if(!stack_is_empty(dragon->minCut)){
        stack_destroy(dragon->minCut);
        dragon->minCut=NULL;
    }
    if(dragon->schNode != NULL){
        sNode_destroy(schNode);
        dragon->schNode = NULL;
    }
    free(dragon);
}

int LlenarDragon(DragonP dragon){
   /*  
 * Lee todos los datos del network donde se correra el algoritmo desde la 
 * entrada estandard y los carga en N usando CargarUnLado() 
 * input:   Network
 * output:  1 si no hubo error,
 *          0 en caso contrario.
*/
    edge * xy = NULL;
    dragon = dragon_rise();
    if (dragon->rise != NULL){
        /* Mientras pueda leer un lado lo agrega al arreglo de edges
         * y al de busquedas. Agregar al arreglo de edges es un side-effect
         * de CargarUnLado().
         */
        while(CargarUnLado(dragon->edgeArr, xy)){
            sNode_add(dragon->schNode, xy);
        }
    }
}

// esta funcion creo que tambien iria en API.c
int ECAML(DragonP dragon){
/*
 * Busca un camino aumentante de menor longitud (hasta encontrar t) 
 * y actualiza en N los datos asociados a la busqueda. 
 * input:   Network
 * output:  1 si se llega a t,
 *          0 si no llega a t,
 *         -1 si ocurrio error.
*/
    result = -1;
    queue Q;
    Q = queue_new(); /*TODO*/
    s = sNode_search(SOURCE);
    enqueue(Q, s);
    S = vertTree_new();/*TODO*/
    vertTree_add(S, s);/*TODO*/
    while(!queue_is_empty(Q) || queue_head(Q)!= t){
        forward_search(Q, S);
        backward_search(Q, S);
        dequeue(Q);
    }
    if(vertTree_exists(S, t)){/*TODO*/
        result = 1
    }else{
        /*encontrar corte*//*TODO*/
        result = 0
    }
}

int DondeEstamosParados(DragonP N){
/*
 * Indica en que estado se encuentra (en curso) el algoritmo para la busqueda
 * de flujo maximal y el camino aumentante de menor longitud (posible corte)
 * input:   Network
 * output:  100*a + 10*b + c donde 'a' indica si es flujo maximal o no,
 *                                 'b' indica si ECAML llego a 't' o no,
 *                                 'c' indica si ECAML actualizo el flujo o no.
 *          1 en caso positivo, 0 en caso negativo.
*/
    int *arr;
    arr = dragon->whereWeAre;
    return(arr[0]*100 + arr[1]*10 + arr[2]);
}
u32 AumentarFlujo(DragonP dragon){
/*
 * Actualiza el flujo en el network N.
 * Precondicion: la busqueda con ECAML debe haber llegado a 't' pero todavia no
 *              haber actualizado el flujo.
 * input:   Network
 * output:  valor por el cual se aumenta el flujo
 *          0 si ocurrio error (en particular, incumplimiento por precondicion)
*/
    u64 flow
    if(DondeEstamosParados(dragon) mod 100 >= 10 ){/*esto no seria precondicion?*/
        path = vertTree_search(t);
        flow = path->cap;
        while(path != s){
            path = vertTree_search(path)->ancestor;
            
        }
    }
}