#include "API.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct cuadrupleSt{
	u32 father;
	u32 son;
	u32 init_cap;
	u32 curr_cap;
} *cuadruple;

struct ENetwork{
	u32 vflujo; /*valor del flujo del network(auxiliar o no)*/
	cuadruple *edge; /* ordenado por BFS*/
	u32 *S; /*corte*/
	int debleer; /*SOLO para debbuggin, eliminarlo cuando ya no haga falta*/
	int debaum; /*SOLO para debbuggin, eliminarlo cuando ya no haga falta*/
};


EstadoNetwork networkNuevo(int Verbosidad){
	EstadoNetwork Net;
	Net = (EstadoNetwork) malloc (sizeof(struct ENetwork));
	Net->debleer = 5;
	Net->debaum = 5;
	printf ("se creo network\n");
return Net;
}

int chauNetwork(EstadoNetwork N){
	int n = 0;
	
	assert(N != NULL);
	free(N);
	if (N == NULL){
		printf ("se destruyo network\n");
		n = 1;
	}
return n;
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
