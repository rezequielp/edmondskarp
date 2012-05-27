#include "API.h"
#include "edge.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "search_node.h>


static bool add_verbose (EstadoNetwork net, int verbose);
static void forward_search(ENetwork N, int x);
static void backward_search(ENetwork N, int x);

struct ENetwork{
	int verb[3]; /*verbosidad*/
	u32 vflujo; /*valor del flujo del network(auxiliar o no)*/
	edArray edarr;
	u32 * cut; /*corte*/
	search_node * sNodes/*arreglo de busqueda*/
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
			net->cut = new_queue();/*ver si se llama asi la funcion*/
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
	lexer *input;
	edge *xy;
	int clean = 0;
	
	input = lexer_new(stdin);
	if (input! = NULL){
		/*se parsea un lado*/
		xy = parse_edge(input);
		/*se corre el parseo hasta la siguiente linea (o fin de archivo)*/
		clean = parse_next_line (input);
		/*si los parseos salieron bien y no se encontro basura, se agrega el lado*/
		if (xy != NULL && clean){
			edArray_add(net->edarr, xy);
			/*agregar tmb al array de busqueda*/
		/*se encontro basura, se destruye el lado*/
		}else if (!clean){
			edge_destroy(xy);
		}
			
		lexer_destroy(input);
	}
	
return clean;
}

int AumentarFlujo(EstadoNetwork net){
	u32 vertex;
	int result = 0;
	set aux_cut = NULL;
	u32 temp_flow = 0;
	
	assert (net != NULL);
	
	/*Capaz usemos el TAD queue del AYED2 para los cortes*/
	aux_cut = new_queue();/*ver si esta funcion se llama asi*/
	/*aca podemos devolver error si no hubo memoria para el corte*/
	
	do{
		vertex = head(aux_cut);/*ver bien que pasa con el elem en la cola*/
		pop(aux_cut);
		if(vertex != SINK){
			forward_search(net, vertex);
			backward_search(net, vertex);
		}
	}while (get_size(aux_cut) != 0 && vertex != SINK);
	
	if(vertex == SINK){
		incr_flow(net);
		result = 1;
	}
	print_verb(net->verb, result);

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
void forward_search(ENetwork Net, int x){
	for(los vecinos que entran en x y que pertenecen al corte){
		if(flujo(x,q)< capacidad(x,q)){
			Q[Net.Next] = q
			S = {q} U S;
			a(q) = x
			E(q) = min(E(x), cap(x,q)-flujo(x,q))
			l(q) = 1
		}
	}
}
void backward_search(ENetwork Net, int x);{
	
}


