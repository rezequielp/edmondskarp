#ifndef API_H
#define API_H
#include "edge.h"


typedef struct NetworkSt *DragonP;

typedef unsigned int u32;

/*Constructor de un dragon*/
DragonP dragon_rise(void);

/*Destructor de dragones*/
void dragon_slayer(dragonP dragon){

int LlenarDragon(DragonP N);
/*  
 * Lee todos los datos del network donde se correra el algoritmo desde la 
 * entrada estandard y los carga en N usando CargarUnLado() 
 * input:   Network
 * output:  1 si no hubo error,
 *          0 en caso contrario.
*/

// esta funcion iria en API.c
int CargarUnLado(DragonP N);
/* 
 * Lee de un input un lado y lo agrega a N con un flujo 0.
 * input:  'x y c' (sin comillas) donde el lado es 'xy' y 'c' es su capacidad.
 *          Los valores seran u32. Se asume que si existe 'xy' entonces 
 *          no formara parte de  la entrada el lado 'yx', no habra lados repetidos 
 *          ni loops.
 * output:  1 si no hubo error,
 *          0 en caso contrario.
*/

// esta funcion creo que tambien iria en API.c
int ECAML(DragonP N);
/*
 * Busca un camino aumentante de menor longitud (hasta encontrar t) 
 * y actualiza en N los datos asociados a la busqueda. 
 * input:   Network
 * output:  1 si se llega a t,
 *          0 si no llega a t,
 *         -1 si ocurrio error.
*/

int DondeEstamosParados(DragonP N);
/*
 * Indica en que estado se encuentra (en curso) el algoritmo para la busqueda
 * de flujo maximal y el camino aumentante de menor longitud (posible corte)
 * input:   Network
 * output:  100*a + 10*b + c donde 'a' indica si es flujo maximal o no,
 *                                 'b' indica si ECAML llego a 't' o no,
 *                                 'c' indica si ECAML actualizo el flujo o no.
 *          1 en caso positivo, 0 en caso negativo.
*/

u32 AumentarFlujo(DragonP N);
/*
 * Actualiza el flujo en el network N.
 * Precondicion: la busqueda con ECAML debe haber llegado a 't' pero todavia no
 *              haber actualizado el flujo.
 * input:   Network
 * output:  valor por el cual se aumenta el flujo
 *          0 si ocurrio error (en particular, incumplimiento por precondicion)
*/


#endif