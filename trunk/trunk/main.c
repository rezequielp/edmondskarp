#include "API.h"
#include <stdio.h>
#include <stdlib.h>

#define EOF '\0'


static void file_to_stdin(FILE path);
static bool controlar_parametros(int argc, char * argv[]);



void main(int argc, char * argv[]){
        int i,aux, is_eof;      /*indice*/
        EstadoNetwork network;  /*network principal*/
        char terminador;
        FILE archivo;
        aux = 1;
        if (controlar_parametros(int argc, char * argv[])){
                printf("Error al ingresar datos\n");
                exit(EXIT_FAILURE);
        }
	net = networkNuevo(argv[2]);
        fflush(stdin);/*limpio el input antes de usarlo*/
        if(argc==3)
                archivo = fopen(archivo)
        do{
                if(argc==3)
                        is_eof = file_to_stdin(path);
                leerUnLado(network);
                fflush(STDIN);
        }while(is_eof != -1 && terminador == C);
        /*que el flujo no se pueda aumentar no es un error. 
         *poner otro nombre a la variable, que sea mas representativo.
        */
        while(aux == 1){
                aux = aumentarFlujo(network);
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
