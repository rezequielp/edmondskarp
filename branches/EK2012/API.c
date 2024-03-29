#include "API.h"
#include "edge.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "search_node.h>

#define MIN(x,y) (x)<(y) ? (x) : (y)

static bool add_verbose (EstadoNetwork net, int verbose);
static void forward_search(ENetwork N, int x);
static void backward_search(ENetwork N, int x);
increase_flow();

struct ENetwork{
	int verb[3]; /*verbosidad*/
	u32 vflujo; /*valor del flujo del network(auxiliar o no)*/
	edArray edarr;
	u32 * cut_S; /*corte*/
	search_node * sNodes;/*arreglo de busqueda*/
	u32 cap_road;/*para saber la capacidad maxima del camino actual*/
};

/*Agrega la verbosidad al network
 * verbosidades validas: (0,1,2,10,11,12,100,101,102,110,111,112)
 * Pre: net != NULL
 * Ret: true si no hubo problemas
 */
bool add_verbose (EstadoNetwork net, int verbose){
	bool result = true;
	
	assert(net != NULL);
	net->verb[0] = verbose/100;	/*imprimir corte minimal?*/
	net->verb[1] = (verbose/10)%10;	/*imprimir flujo maximal?*/
	net->verb[2] = verbose%10;	/*nivel de verb durante la corrida*/

	/* verifico que sea una verbosidad valida*/	
	if 	(net->verb[0] > 1 || net->verb[1] > 1 || net->verb[2] > 2){
		printf("Verbosidad no permitida\n");
		result = false;
	}
	return result;
}


EstadoNetwork networkNuevo(int Verbosidad){
	EstadoNetwork net = NULL;
	net = (EstadoNetwork) malloc(sizeof(EstadoNetworkSt));
	if (net != NULL)){
			net->edarr= edArray_new();
			net->cut = stk_empty();/*ver si se llama asi la funcion*/
			net->vflujo = 0;
			if (net->edarr == NULL  || !add_verbose(net, Verbosidad){
				chauNetwork(net);
				net = NULL;
			}
	}	
	return net;
}

/*nunca va a devolver 0, porque no hay error que suceda*/
int chauNetwork(EstadoNetwork net){
	int result = 0;
	assert(net != NULL);
	
	if (net->edarr != NULL)
		edArray_destroy(net->edarr);
	free(net);
	if (net == NULL){
		result = 1;
	}
return result;
}



int LeerUnLado(EstadoNetwork net){
	int result = 0;
	lexer *input;
	edge *xy;
	int clean; /*indica si no se encontro basura al parsear*/
	
	input = lexer_new(stdin);
	if (input! = NULL){
		/*se parsea un lado*/
		xy = parse_edge(input);
		/*se corre el parseo hasta la siguiente linea (o fin de archivo)*/
		clean = parse_next_line (input);
		/*si parseo bien el lado y no se encontro basura, se agrega al Network*/
		if (xy != NULL && clean){
			/*aca tmb falta chequear q no haya ocurrido error al agregarlo*/
			edArray_add(net->edarr, xy);
			/*agregar tmb al array de busqueda*/
			/* result es 1 si se agrego bien en los arreglos*/
			result = 1;
		/*si se encontro basura, se destruye el lado*/
		}else if (xy != NULL){
			edge_destroy(xy);
		}
		lexer_destroy(input);
	}
	
	return result;
}

int AumentarFlujo(EstadoNetwork net){
	u32 vertex;
	int result = 0;
	set aux_cut = NULL;
	u32 temp_flow = 0;
	
	assert (net != NULL);
	
	aux_cut = queue_new();
	aux_stk = stk_empty();
	
	net->cap_road = MAX_NUMBER;
	
	/* se agrega 's' (es 0 en u32)*/
	aux_cut = enqueue(aux_cut, 0);
	aux_stk = (aux_stk, 0, 0, 1);
	do{
		vertex = head(aux_cut);
		its_ok = forward_search(net, vertex, aux_cut, aux_stk);
		its_ok = backward_search(net, vertex, aux_cut, aux_stk);
		aux_cut = dequeue(aux_cut);
		
	}while (its_ok != FLOW_ERR && !queue_is_empty(aux_cut));

	if (its_ok != FLOW_ERR){
		if(stk_top_vertex(aux_stk) == 1){
			result = increase_flow(/*ver*/);
		}else/*ver*/
	}else{
		result = FLOW_ERR;
	}

	return result;
}

void ImprimirFlujoMaximal(EstadoNetwork N){
	u32 *vertice;
	
	if(net->verb[1] == 1){
			printf ("Flujo Maximal:\n");
			while(get_size(aux_cut) > 0){
				vertice = pop_head(aux_cut);
				printf("", vert);
			}
	}
	printf ("Valor flujo maximal: %i\n", net->vflow);
}

void forward_search(ENetwork Net, u32 x, queue Q, stack S){
	
	u32 q = 0;
	u32 err = 0;
	u32 i = 0;
	u32 size = 0;
	edArryay *edges = NULL;
	
	err = schArray_list_edge(x,FORWARD,edges);
	size = edArray_size(edges);
	
	
	for(i=0; i < size; i++){
		q = edge_get_y(edges[i]);
		if(!belongs(S,q) && !edge_saturated(edges[i], FORWARD)){
			/*Agregar q a Q*/
			Q = enqueue(Q,q);
			/*S es la pila*/
			/*q es el vertice*/
			/*x es el ancestro*/
			/*FORWARD es el sentido*/
			S = enqueue(S,q,x,FORWARD);
			/*Veo si la capacidad del camino debe o no ser modificada*/
			/**/
			Net->cap_road = MIN(Net->cap_road, capacity(edges[i])-flow(edges[i]));
		}
	}
	edArray_destroy (edges);
}

void backward_search(ENetwork Net, u32 x, queue Q, stack S){
	
	u32 q = 0;
	u32 err = 0;
	u32 i = 0;
	u32 size = 0;
	edArryay *edges = NULL;
	
	err = schArray_list_edge(x,BACKWARD,edges);
	size = edArray_size(edges);
	
	for(i=0; i < size; i++){
		q = edge_get_y(edges[i]);
		if(!belongs(S,q) && !edge_saturated(edges[i], BACKWARD)){
			/*Agregar q a Q*/
			Q = enqueue(Q,q);
			/*S es la pila*/
			/*q es el vertice*/
			/*x es el ancestro*/
			/*FORWARD es el sentido*/
			S = enqueue(S,q,x,BACKWARD);
			/*Veo si la capacidad del camino debe o no ser modificada*/
			/**/
			Net->cap_road = MIN(Net->cap_road, flow(edges[i]));
		}
	}
	edArray_destroy (edges);
}