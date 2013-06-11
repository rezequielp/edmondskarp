/*
 * PARSER DE ARISTAS (LADOS)
 * El path es un archivo con 3 int separados por un espacio entre ellos
 * y luego un '\n', esta estructura puede estar repetida
 * varias veces. al final hay un EOF.
 * 
 * s::= {'+int+' '+int+' '+int+'\n'}+EOF
 * 
 * Ej: 2 4 6\n2 4 54\n321321 321321 4888\nEOF
*/

#ifndef _PARSER_EDGE_H
#define _PARSER_EDGE_H

#include "auxlibs/lexer.h"
#include "edge.h"

#define PARSER_OK 0
#define PARSER_ERR 1

/* Lee todo un edge de `input' hasta llegar a un fin de línea o de archivo
 * Pre:
 *  input != NULL
 *  ! lexer_is_off (input)
 * Ret:
 *  un puntero a un nuevo edge (a liberar por el llamador),
 *  o NULL en caso de error.
 * ENSURES:
 *  Se consumió input hasta el primer error o hasta completar el edge.
 *  No se consumió ningun \n.
 *  Si lo que se consumió es un edge valido, `result' contiene la
 *  estructura correspondiente.
 */
edge *parse_edge(Lexer *input);


/* Consume el fin de línea. Indica si encontro basura antes del fin de línea.
 * Pre:
 *     input != NULL
 * Ret:
 *   true en caso de éxito (se consumió hasta el fin de línea o archivo
 * 		sin encontrar nada)
 *   false si encuentra algo, pero igual los consume.
 * ENSURES:
 *     no se consumió más entrada de la necesaria
 *     el lexer esta detenido justo luego de un \n o en el fin de archivo.
 */
int parse_next_line (Lexer *input);

#endif