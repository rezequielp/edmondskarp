
#include "API.h"
#include <stdio.h>
#include <stdlib.h>

#define EOF '\0'

static void file_to_input(FILE path, int indice);
static bool controlar_parametros(int argc, char * argv[]);

void main(int argc, char * argv[]){
	int i,aux;			/*indice*/
	EstadoNetwork network;	/*network principal*/
	char terminador;
	i = 0;
	aux = 1;
	if (controlar_parametros(int argc, char * argv[])){
		printf("Error al ingresar datos\n");
		exit(EXIT_FAILURE);
	}
	net = networkNuevo(argv[2]);
	do{
		if(argc==3)
			file_to_input(path,i);
		terminador = getchar();
		leerUnLado(network);
		fflush(stdin);
		i++;
	}while(terminador == EOF && terminador == C);
	
	while(aux == 1){
		aux = aumentarFlujo(network)
	}
	if (aux == -1)){
		printf("error del aumentarFlujo\n");
		if(chauNetwork(network) == 0)
			printf("error a liberar el network");
		exit(EXIT_FAILURE);
	}
	imprimirFlujoMaximal(network);
	if(chauNetwork(network) == 0)
		printf("error a liberar el network");
}
