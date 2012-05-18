#include "API.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>



static bool add_verbose (EstadoNetwork net, int verbose);



typedef struct cuadrupleSt{
	u32 father;
	u32 son;
	u32 init_cap;
	u32 curr_cap;
} *cuadruple;

struct ENetwork{
	int verb[3]; /*verbosidad*/
	u32 vflujo; /*valor del flujo del network(auxiliar o no)*/
	cuadruple *edge; /* ordenado por BFS*/
	u32 size_edge; /*cantidad de elementos de edge*/
	u32 *S; /*corte*/
	int debleer; /*SOLO para debbuggin, eliminarlo cuando ya no haga falta*/
	int debaum; /*SOLO para debbuggin, eliminarlo cuando ya no haga falta*/
};



/*Agrega la verbosidad al network
 * verbosidades validas: (0,1,2,10,11,12,100,101,102,110,111,112)
 * Pre: net != NULL
 * Ret: true si no hubo problemas
 */
bool add_verbose (EstadoNetwork net, int verbose){
	
	assert(net != NULL);
	net->verb[0] = verbose/100;	/*imprimir corte minimal?*/
	net->verb[1] = (verbose/10)%10;	/*imprimir flujo maximal?*/
	net->verb[2] = verbose%10;	/*nivel de verb durante la corrida*/
	
	/* retorno verificando que sea una verbosidad valida*/
	return (net->verb[0] <= 1 && net->verb[1] <=1 && net->verb[2] <= 2);
}


EstadoNetwork networkNuevo(int Verbosidad){
	EstadoNetwork net = NULL;
	net = (EstadoNetwork) malloc(sizeof(EstadoNetworkSt));
	if (net != NULL){
		if (add_verbose(net, Verbosidad)){
			net->edge = NULL;
			net->size_edge = 0;
			net->S = NULL;
			net->debleer = 5;	/*debuggin*/
			net->debaum = 5;	/*debuggin*/
		}else{
			printf("Verbosidad no permitida\n");
			chauNetwork(net);
			net = NULL;
		}
	}
	/*falta errno por no poder malloquear net*/
	
return net;
}

/*nunca va a devolver 0, porque no hay error que suceda*/
int chauNetwork(EstadoNetwork N){
	int result = 0;
	
	assert(N != NULL);
	while (N->size_edge > 0){
		free(N->edge[N->size_edge-1]);
		N->size_edge--;
	}
	if (N->edge != NULL){
		free(N->edge);
	}
	if (N->S != NULL){
		free(N->S);
	}
	free(N);
	if (N == NULL){
		printf ("se destruyo network\n");
		result = 1;
	}
return result;
}

int LeerUnLado(EstadoNetwork N){
	int n;
	if (N->debleer != 0){
		N->debleer--;
		n = 1;
		printf("se leyo lado\n");
	}else{
		n = 0;
		printf("se termino de leer lados\n");
	}
return n;
}

int AumentarFlujo(EstadoNetwork N){
	int n;
	if (N->debaum != 0){
		N->debaum--;
		n = 1;
		printf("se aumento flujo\n");
	}else{
		n = 0;
		printf("se termino de aumentar flujo\n");
	}
return n;
}

void ImprimirFlujoMaximal(EstadoNetwork N){
	printf ("se imprimio flujo maximal\n");
}
