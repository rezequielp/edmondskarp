#include "API.h"
#include <stdlib.h>
#include "constants.h"/*s=0, t=1*/


/*Estructura del network*/
typedef struct NetworkSt{
    SNodes network;     /*El network en forma de arbol binario de busqueda*/
    u64 flow;           /*Valor del flujo del network*/
    SPNodes cut;        /*Un abb de punteros a nodos para el corte*/
    Stack way;          /*Camino en forma de pila*/
    u64 tempFlow;       /*Cant de flujo a aumentar (cap min del camino actual)*/
    int whereWeAre[3];  /*[¿flujo maximal?, ¿llego a t?, ¿aumento flujo?]*/
} DragonSt;


/* Constructores y destructores de datos */

DragonP NuevoDragon(){
    DragonP dragon = NULL; /*Nuevo network*/
    
    dragon = (DragonP) malloc(sizeof(DragonSt));
    /*Nos prevenimos de que no se haya dado memoria*/
    if (dragon != NULL)){
            dragon->network = snodes_new();
            dragon->flow = 0;
            dragon->cut = spnodes_new();
            dragon->way = NULL;
            /*Si no se le asigno memoria a algo, liberamos todo lo anterior*/
            if (dragon->network == NULL || dragon->cut == NULL){
                DestruirDragon(dragon);
                dragon = NULL;
            }
            dragon->whereWeAre = {0, 0, 0};
    }
    return dragon;
}

int DestruirDragon(DragonP dragon){
    assert(dragon != NULL);
    
    if (dragon->network != NULL){
        snodes_destroy(dragon->network);
        dragon->network = NULL;
    }
    if(!stack_is_empty(dragon->way)){
        stack_destroy(dragon->way);
        dragon->way = NULL;
    }
    if(dragon->cut != NULL){
        spnode_destroy(dragon->cut);
        dragon->cut = NULL;
    }
    free(dragon);
    /*En esta funcion nunca ocurre un error, siempre termina bien!*/
    return 1;
}


/* Cargadores de nuevos datos */

int CargarUnLado(DragonP dragon, u32 x, u32 y, u32 c){
    int result = 0;
    
    /*Hay que programar primero el TAD SNodes*/
    
    return result;
}

int LlenarDragon(DragonP dragon){
    int result = 1;
    u32 x, y, c = 0;
    lexer *input; /*analizador lexico por lineas de un archivo*/
    int clean;  /*Indica si no se encontro basura al parsear*/
    
    assert(dragon != NULL);
    /*construyo el lexer sobre la entrada estandar*/
    input = lexer_new(stdin);
    
    if (input! = NULL){
        /*Leo los lados mientras no llegue a un fin de archivo o haya ocurrido
          algun error*/
        while (!lexer_is_off(input) && (result != 0)){
            /*se parsea un lado*/
            result = parse_edge(input, x, y, c);
            /*se corre el parseo hasta la siguiente linea (o fin de archivo)*/
            clean = parse_next_line(input);
            /*lado bien parseado y no se encontro basura, se agrega al network*/
            if (result != 0 && clean != 0){
                result = CargarUnLado(dragon->network, x, y, c);
            }
        }
        lexer_destroy(input);
    }
    return result;
}


/* Operadores de calculos y de busqueda */

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

u64 Sumar64(u64 a, u32 b){
    
}


/* Funciones de consultas */

int DondeEstamosParados(DragonP dragon){
/*
 * Indica en que estado se encuentra (en curso) el algoritmo para la busqueda
 * de flujo maximal y el camino aumentante de menor longitud (posible corte)
 * input:   Network
 * output:  100*a + 10*b + c donde 'a' indica si es flujo maximal o no,
 *                                 'b' indica si ECAML llego a 't' o no,
 *                                 'c' indica si ECAML actualizo el flujo o no.
 *          Las variables son 1 en caso positivo y 0 en caso negativo.
*/
    int *arr;
    arr = dragon->whereWeAre;
    return(arr[0]*100 + arr[1]*10 + arr[2]);
}


/* Impresores */

u32 AumentarFlujoYtambienImprimirCamino(){
    
}

void ImprimirFlujo(DragonP N){
    
}

void ImprimirCorte(DragonP N){
    
}