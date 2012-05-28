#include "API.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


static bool file_to_stdin(FILE *fd);
static bool ctrl_parameters(int argc, char * argv[]);
static bool load_from_file(EstadoNetwork network, char * path);
static bool load_from_stdin(EstadoNetwork network);
static bool calculate_max_flow(EstadoNetwork network);


int main(int argc, char * argv[]){
	bool its_ok = false;      /*indicador de operaciones exitosas*/
	EstadoNetwork network = NULL;  /*network principal*/
	
	/*Se controlan los parametros de ingreso*/
	if (ctrl_parameters(argc, argv)){
		/* Se crea un nuevo network con la verbosidad*/
		network = networkNuevo(atoi(argv[2]));
	}

	if (network != NULL){
		/* Si el network se carga de un archivo o de estandar input*/
		if(argc == 4){
			its_ok = load_from_file(network, argv[3]);
		}else{
			its_ok = load_from_stdin(network);
		}
		/*se calcula e imprime el flujo maximal*/
		if (its_ok){
			its_ok = calculate_max_flow(network);
		}
		/* destruyo el network*/
		if(chauNetwork(network) == 1){
			printf("Error al intentar liberar el network\n");
			its_ok = false;
		}
	}

	/*exit satisfactorio, o no*/
	if (!its_ok){
		exit(EXIT_FAILURE);
	}
	return 0;
}

/* Se controlan los parametros claves
 * Ret: true si no hubo error
 */
bool ctrl_parameters (int argc, char * argv[]){
	bool result = false;
	
	if (argc == 3 || argc == 4){
		if (strcmp(argv[1], "-v") == 0){
			result = true;
		}
	}
	if (!result){
		printf("Error al ingresar parametros\n");
		/*Aca tambien se puede imprir la ayuda sintactica*/
	}
	return result;
}

/*Carga los lados del network desde un archivo.
* Pre: network != NULL
* Ret: true, si no hubo error
*/
bool load_from_file(EstadoNetwork network, char * path){
	FILE *fd;
	bool result = true;
	int readed_edge;
	
	assert(network != NULL);
	/* Se abre el archivo con permiso de solo lectura*/
	fd = fopen(path, "r");
	if (fd == NULL){
		printf("Error al intentar abrir el archivo\n");
		result = false;
	}else{
		do{
			/* se intenta escribir una linea datos del archivo en stdinput*/
			if (!file_to_stdin(fd)){
				result = false;
				break;
			}
			readed_edge = LeerUnLado(network);
			/* no hace falta limpiar el input porq lexer se come todo lo leido
			* caso vacio -> leerUnLado retorna 0*/
		}while (readed_edge);
	}
	/*se cierra el archivo*/
	if (fd != NULL && fclose(fd) != 0){
		printf("Error al intentar cerrar el archivo\n");
		result = false;
	}
	return result;
}


/*Carga los lados del network desde el stdin. Ingreso manual por consola
 * Pre: network != NULL
 * Ret: true si no hubo error (en realidad siempre sera true)
 */
bool load_from_stdin(EstadoNetwork network){
	int readed_side; /*captura el resultado de leerUnLado*/
	bool result = true; /*resultado de la funcion*/
	
	assert(network != NULL);
	do{
		readed_side = LeerUnLado(network);
		/* no hace falta limpiar el input porq lexer se come todo lo leido
		* caso vacio -> leerUnLado retorna 0*/
	}while (readed_side);
	
	return result;
}


/*Calcula e imprime flujo maximal.
 * Pre: network != NULL
 * Ret: true si no hubo error
 */
bool calculate_max_flow(EstadoNetwork network){
	int flow_increased;	/*captura el resultado de aumentarflujo*/
	bool result = true; /*resultado de la funcion*/

	assert(network != NULL);
	/*que el flujo no se pueda aumentar no es un error.*/
	do{
		flow_increased = AumentarFlujo(network);
	}while(flow_increased);
	
	/*imprimo el resultado del calculo*/
	if (!flow_increased){
		ImprimirFlujoMaximal(network);
	}else if (flow_increased == FLOW_ERR){
		printf("Error al intentar aumentar el flujo\n");
		result = false;
	}
	
	return result;
}


/*copia hasta encontrar un '\n' (o EOF) desde el archivo path al stdin.
 * Pre: fd != NULL
 * Ret: true si no hubo error.
 */
bool file_to_stdin(FILE *fd){
        char * line = NULL; /*buffer para almacenar las lineas leidas*/
        size_t len;  /*tamaño del buffer*/
        int large; /*cantidad de elementos leidos por getline*/
        int count; /*cantidad de datos escritos por fwrite*/
        bool result = true;

		assert(fd != NULL);
		len = sizeof(char);
        line = (char*) malloc(len);
        /*getline hace un realloc si el buffer es chico ;)
         *esto realentiza el cargado pero facilita el uso de buffers
         * dinamicos ;)
         */
        large = getline(&line, &len, fd);
		if (large != EOF){
			count = fwrite(line, sizeof(char), large, stdin);
			printf("count %i = %i large ? \n", count, large);
			if (count != large){
				printf("Error al intentar escribir en estandar input\n");
				result = false;
			}
		}
		free(line);
        return result;
}
