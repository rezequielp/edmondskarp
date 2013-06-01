#ifndef API_H
#define API_H



typedef DragonSt *DragonP;

typedef unsigned int u32;

DragonP NuevoDragon();
/* 
 * Constructor de un nuevo network. Aloca memoria e inicializa la estructura.
 * Output:  Un puntero  a la estructura, si no hubo error
 *                      NULL en caso de error.
*/

int DestruirDragon(DragonP N);
/* 
 * Destructor de un network. Se libera toda memoria alocada.
 * Input:   Network no nulo
 * Output:  1 si no hubo error
 *          0 caso contrario
*/

int CargarUnLado(DragonP N, u32 x, u32 y, u32 c);
/* 
 * Carga el lado 'xy' con capacidad 'c' en el network N
 * y con un flujo inicial 0.
 * Input:   Network no nulo
 *          'x' e 'y', vertices unidos por una arista de 'x' a 'y'
 *          'c' capacidad (de flujo) de la arista
 * Output:  1 si no hubo error
 *          0 caso contrario
*/
    
int LlenarDragon(DragonP N);
/*  
 * Lee todos los datos del network donde se correra el algoritmo desde la 
 * entrada estandard y los carga en N usando CargarUnLado() 
 * 'x y c' (sin comillas) donde el lado es 'xy' y 'c' es su capacidad.
 * Los valores seran u32. Se asume que si existe el lado 'xy' entonces 
 * el lado 'yx' no formara parte de  la entrada, no habra lados repetidos 
 * ni loops.
 * Input:   Network no nulo
 * Output:  1 si no hubo error,
 *          0 en caso contrario.
*/

int ECAML(DragonP N);
/*
 * Busca un camino aumentante de menor longitud (hasta encontrar t) 
 * y actualiza en N los datos asociados a la busqueda. 
 * Input:   Network no nulo
 * Output:  1 si se llega a t,
 *          0 si no llega a t,
 *         -1 si ocurrio error.
*/

int DondeEstamosParados(DragonP N);
/*
 * Indica en que estado se encuentra (en curso) el algoritmo para la busqueda
 * de flujo maximal y el camino aumentante de menor longitud (posible corte)
 * Input:   Network no nulo
 * Output:  100*a + 10*b + c donde 'a' indica si es flujo maximal o no,
 *                                 'b' indica si ECAML llego a 't' o no,
 *                                 'c' indica si ECAML actualizo el flujo o no.
 *          Las variables son 1 en caso positivo y 0 en caso negativo.
*/

u32 AumentarFlujo(DragonP N);
/*
 * Actualiza el flujo en el network N.
 * Precondicion: la busqueda con ECAML debe haber llegado a 't' pero todavia no
 *              haber actualizado el flujo.
 * Input:   Network no nulo
 * Output:  valor del aumento de flujo
 *          0 si ocurrio error (en particular, incumplimiento por precondicion)
*/

u32 AumentarFlujoYtambienImprimirCamino();
/*
 * Actualiza el flujo en el network N e imprime por la salida estandard
 * el camino aumentante y el aumento a lo largo de el.
 * Formato: t:x_r:...:x_1:s: <cantDelIncremento>
 *          (:) indica lado forward
 *          (|) indica lado backward
 * Precondicion: la busqueda con ECAML debe haber llegado a 't' pero todavia no
 *              haber actualizado el flujo.
 * Input:   Network no nulo
 * Output:  valor del aumento de flujo
 *          0 si ocurrio error (en particular, incumplimiento por precondicion)
*/

void ImprimirFlujo(DragonP N);
/*
 * Imprime por la salida estandard el fujo actual
 * Formato: Valor del flujo _ : <valorDelFlujo>
 *          (_) es la palabra "maximal o "no maximal"
 * Input:   Network no nulo
*/

void ImprimirCorte(DragonP N);
/*
 * Imprime por la salida estandard un corte minimal del network y su capacidad
 * Formato: Corte Minimal: S = {s, x_1,...}
 *          Capacidad: <Valorcapacidad>
 * Input:   Network no nulo
*/

u64 Sumar64(u64 a, u32 b);
/*
 * suma 'a' y 'b' correctamente (modulo 2^64)
 * Input:   'a' a lo sumo de 50bits
 *          'b' de 32bits
 * Output: resultado no mayor a 2^64
*/

#endif