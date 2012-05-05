#include "API.h"

typedef struct ENetwork{
	u32 vflujo; /*valor del flujo del network(auxiliar o no)*/
	cuadruple * edge; /* ordenado por BFS*/
	u32 *S; /*corte*/
}EstadoNetworkSt;

typedef struct cuadrupleSt{
	u32 father;
	u32 son;
	u32 init_cap;
	u32 curr_cap;
} *cuadruple;


EstadoNetwork networkNuevo(int Verbosidad){
	EstadoNetwork Net;
return Net;
}

int chauNetwork(EstadoNetwork N){
	int n;
return n;
}

int leerUnLado(EstadoNetwork N){
	int n;
return n;
}

int aumentarFlujo(EstadoNetwork N){
	int n;
return n;
}

void imprimirFlujoMaximal(EstadoNetwork N){

}
