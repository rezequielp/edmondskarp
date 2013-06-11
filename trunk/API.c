#include "API.h"
#include <stdlib.h>
#include <math.h>

#define SOURCE 0
#define SINK 1
#define FORWARD 1
#define BACKWARD -1

/*Estructura del network*/
/*Cuando termina de correr E-K Network->flow es flujo maximal y NetworkSt->cut es corte minimal */
typedef struct NetworkSt{
    Abb network;     /*El network en forma de arbol binario de busqueda*/
    u64 flow;           /*Valor del flujo del network*/
    Abb cut;            /*Un abb de punteros a nodos para el corte*/
    queue path;        /*Camino en forma de un flujo de caracteres*/
    u64 tempFlow;       /*Cant de flujo a aumentar (cap min del camino actual)*/
    int whereWeAre[3];  /*[¿flujo maximal?, ¿llego a t?, ¿aumento flujo?]*/
} DragonSt;


/* Constructores y destructores de datos */

DragonP NuevoDragon(){
    DragonP dragon = NULL; /*Nuevo network*/
    
    dragon = (DragonP) malloc(sizeof(DragonSt));
    /*Nos prevenimos de que no se haya dado memoria*/
    if (dragon != NULL)){
            dragon->network = abb_create();
            dragon->flow = 0;
            dragon->cut = NULL;
            dragon->path = NULL;
            dragon->whereWeAre = {0, 0, 0};
            /*Si no se le asigno memoria a algo, liberamos todo lo anterior*/
            if (dragon->network == NULL || dragon->cut == NULL){
                DestruirDragon(dragon);
                dragon = NULL;
            }
    }
    return dragon;
}

int DestruirDragon(DragonP dragon){
	int i;
	int result = 0;
    assert(dragon != NULL);
    if (dragon->network != NULL){
		netSize = abb_size(dragon->network);
		edgeGarbage = (Edge *) malloc ( netSize * sizeof(struct EdgeSt *));
        netGarbSize = abb_destroy(dragon->network, edgeGarbage);
		/*ahora destruyo los elementos almacenados en el network*/
		if (netGarbSize == netSize){
			dragon->network = NULL;
			for(i=0, i<netGarbSize, i++){
				edge_destroy(edgeGarbage[i]);
			}
			free(netGarbage);
			if(!stack_is_empty(dragon->path)){
			/* TODO */
			/*ver si hay que liberar la estructura en este stack
			 * en el caso que se guarden los datos en una tupla
			 * (edge, direction)
			 */
				stack_destroy(dragon->path, NULL);
				dragon->path = NULL;
			}
		}
	}
	if(dragon->cut != NULL){
		/*los elementos de estaestructura son punteros al arbol
		*no hace falta liberarlos
		*/
		cutSize = abb_size(dragon->cut);
		cutGarbage = (cutNode *) malloc (cutSize * sizeof(struct cutNodeSt *));
		cutGarbSize = 	abb_destroy(dragon->cut, NULL);
		/*ahora destruyo los elementos almacenados en el network*/
		if (cutGarbSize == cutSize){
			dragon->cut = NULL;
			for(i=0, i<cutGarbSize, i++){
				cut_destroy(cutGarbage[i]);
			}
			free(cutGarbage);
		}
	}
	if(dragon->network != NULL && dragon->cut != NULL){
		free(dragon);
		result = 1;
	}
	return result;
}


/* Cargadores de nuevos datos */

int CargarUnLado(DragonP dragon, u32 x, u32 y, u32 c){
    EdgeNode edge;
    int result = 0;
    
    assert(dragon != NULL);
    
    edge = edgeNode_create();
    if (edge != NULL){   
        edgeNode_set(x, y, c);
        result = abb_add(dragon, edge);
    }
    
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
    EdgeNode s = NULL;
    Queue Q = NULL;
    error = 0;
    result = -1;
    CutNode cutNode;
    assert(dragon != NULL);
    
    Q = queue_create();
    if (Q != NULL){
        if (dragon->cut != NULL){
            abb_destroy(dragon->cut, NULL);
        }
        dragon->cut = abb_create();
        /*si no hubo problema para crear*/
        if (dragon->cut != NULL){
            s = abb_search(Abb dragon->network, SOURCE);
            /*clavo un assert porque la busqueda siempre devuelve un edge
             * valido, sino algo hicimos mal*/
            assert(s != NULL);
			error = queue_enqueue(Q, s);
			/*caso especial del tipo cutNode*/
			cutNode = cutNode_create(SOURCE, s, 0);
			if (cutNode != NULL){
				abb_add(dragon->cut, cutNode);
				while((!queue_isEmpty(Q) || queue_head(Q)!= SINK) && error == 0){
					error = forward_search(Q, dragon->cut);
					if (error == 0){
						error = backward_search(Q, dragon->cut);
						queue_dequeue(Q);
					}
				}
				if (error == 0){
					if (abb_exists(dragon->cut, SINK)){
						cutToWat(dragon);
						
						
						cutPivot = abb_search(dragon->cut, SINK)
						flow = edge_getFlow(cutPivot->edge, SINK, cutPivot->direction);
						bconchar(dragon->path, bfromcstr('t'))
						/*mientras no lleguemos a SOURCE*/
						while (cutPivot->edge != NULL){
							/*Buscamos quien agrego a este elem*/
							son = edge_getX(pivot->edge)
							cutPivot = abb_search(dragon->cut, son);
							if(cutPivot->direction == FORWARD){
								flow = fmin(flow, edge_getFlow(cutPivot->edge, son, FORWARD));
							}else{/*BACKWARD*/
								flow = fmin(flow, edge_getFlow(cutPivot->edge, son, BACKWARD));
							}
						}
						result = 1;
					}else{
						result = 0;
					}
				}
			}
        }
        dequeue_destroy(Q);
    }
    return result;
}
/*Pre: t pertenece al corte*/
int fromCutTopath(Dragon dragon){
    Abb cut;
    CutNode cutNode;
    u32 ancestor;
    int wSize = 0;
    int wSizeNew = 0;
    int result = 1;
    
    assert(dragon != NULL);
    
   
    cut = dragon->cut;
    
    if(dragon->path != NULL){ 
        wSize = stack_size(dragon->path);
        stack_destroy(dragon->path, NULL);
    }
    /*se construye el nuevo camino*/
    dragon->path = stack_create();
    if(dragon->path != NULL){
        ancestor = SINK;
        do{
            cutNode = abb_search(cut, x);
            result = stack_bpush(dragon->path, cutNode);
            ancestor = cutNode_getAncestor(cutNode);
        while((cutNode_getX(cutNode) != SOURCE) && (result != 1))}
        wSizeNew = stack_size(dragon->path);
    }
    /*Pos: los caminos son de longitud igual o mayor al anterior calculado*/
    assert(wSize <= wSizeNew);
    return result;
}

u32 AumentarFlujo(DragonP dragon){
/*
 * Actualiza el flujo en el network N.
 * Precondicion: la busqueda con ECAML debe haber llegado a 't' pero todavia no
 *              haber actualizado el flujo.DondeEstamosParados(dragon) = X10
 * input:   Network
 * output:  valor por el cual se aumenta el flujo
 *          0 si ocurrio error (en particular, incumplimiento por precondicion)
*/
    u64 flow;
    int son;
    Edge edgePivot;
    
    if(DondeEstamosParados(dragon)%100 == 10 ){
        /*TODO ESTA FUNCION DEPENDE DE LA IMPLEMENTACION DEL CORTE Y EL CAMINO*/

        }
    }
}
/*funcionara esto??? TODO */
u64 Sumar64(u64 a, u32 b){
	u64 aux;
	auxB = (u64) b;
	return (a+auxB);
}


/* Funciones de consultas */

int DondeEstamosParados(DragonP dragon){
/*
 * Indica en que estado se encuentra (en curso) el algoritmo para la busqueda
 * de flujo maximal y el camino aumentante de menor longitud (posible corte)
 * input:   Network
 * output:  100*a + 10*b + c donde 'a' indica si es flujo maximal o no,
 *                                 'b' indica si ECAML llego a 't' o no,
 *                                 'c' indica si los resultados de ECAML fueron 
 *                                       usados para actualizar el flujo o no.
 *          Las variables son 1 en caso positivo y 0 en caso negativo.
*/
    int *arr;
    arr = dragon->whereWeAre;
    return(arr[0]*100 + arr[1]*10 + arr[2]);
}


/* Impresores */

u32 AumentarFlujoYtambienImprimirCamino(DragonP dragon){
    
    flow = AumentarFlujo();
    
    
    return flow;
}

void ImprimirFlujo(DragonP dragon){
    assert(dragon != NULL);
    /*bardo con imprimir u64*/
    if (DondeEstamosParados(dragon)/100 == 1){
        printf("Flujo Maximal: %u%u \n", dragon->flow[0], dragon->flow[1]);
    }else{
        printf("Flujo no maximal: %u%u \n", dragon->flow[0], dragon->flow[1]);
    }
}

void ImprimirCorte(DragonP dragon){
    assert(dragon != NULL);
    
    /*TODO hay que aplastar el arbol e imprimir los elementos del corte.
     * Lo mejor seria respetar que unicamente se hagan prints en el API.
     */
}

int forward_search(Queue q, Abb cut){
	u32 x;
	Edge edge;
	
	assert(q != NULL && cut != NULL)
	
	x = edge_getX(queue_head(q));
	edge = abb_search(cut, x);
	
}

int backward_search(){

}