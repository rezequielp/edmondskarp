#include "API.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static void file_to_stdin(FILE path);
static bool controlar_parametros(int argc, char * argv[]);



void main(int argc, char * argv[]){
	int up_flow, readed_side;      /*indice*/
	EstadoNetwork network;  /*network principal*/
	Lexer * input = NULL;
	FILE fd;
	
	up_flow = 1;
	readed_side = 1;
	/*Se controlan los parametros de ingreso*/
	if (ctrl_parameters(int argc, char * argv[])){
		printf("Error al ingresar datos\n");
		exit(EXIT_FAILURE);
	}
	/* Si el network se carga de un archivo, se intenta abrirlo (read only)*/
	if(argc==4){
		fd = fopen(argv[3], "r");
		if (!fd){
			printf("Error al intentar abrir el archivo");
			exit(EXIT_FAILURE);
		}
	}
	/* Se crea un nuevo network con la verbosidad ingresada*/
	network = networkNuevo(argv[2]);
	/*limpio el input antes de usarlo (no se si haria falta)*/
	fflush(stdin);
	/* Se crea el lexer sobre stdin*/
	input = lexer_new (stdin);
	/* Se lee hasta que sea EOF y no haya quedado nada por leer*/
	while(!lexer_is_off(input) && readed_side){
		if(argc==4)
			file_to_stdin(fd);
		readed_side = leerUnLado(network);
		/* no hace falta limpiar el input porq lexer se come todo lo leido
		 * no hace falta saber el retorno de file_to_stdin porque si en stdin
		 * no se ingresa nada, entonces leerUnLado retorna 0*/
	}
	lexer_destroy(input);

	/* HASTA ACA LLEGUE*/
	
	/*que el flujo no se pueda aumentar no es un error.
		*poner otro nombre a la variable, que sea mas representativo.
	*/
	while(up_flow){
			up_flow = aumentarFlujo(network);
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



/*copia hasta encontrar un '\n' desde el archivo path al STDIN.
 *Devuelve -1 en caso de error o EOF.
 *Tiene como precondicion que el path es un archivo con 3 int separados por 1 
 *espacio entre ellos y luego un '\n', esta estructura puede estar repetida 
 *varias veces. al final hay un EOF.
 *s::= +{int+' '+int+' '+int+'\n'}+EOF 
 *Ej: 2 4 6\n2 4 5 54\n321321 321321 4888\nEOF
*/
int file_to_stdin(FILE archivo){
        char * line;/*buffer para almacenar las lineas leidas*/
        int large; /*cantidad de elementos leidos por getline*/
        
        fflush(stdin);/*limpio el input antes de usarlo*/ 
        line = (char) malloc (sizeof(struct char));
        
        /*getline hace un realloc si el buffer es chico ;)
         *esto realentiza el cargado pero facilita el uso de buffers dinamicos ;)
         */
        large = getline(line, archivo, )
        write(line, sizeof(struct char), large, STDIN);
        return large;
}
