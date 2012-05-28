#include <assert.h>
#include "edge.h"


struct edgeSt{
	u32 x;
	u32 y;
	u32 cap;
	u32 flow;
	flag_s sense;
};

struct edArraySt{
	u32 *edges;
	u32 counter;
};

/**********************funciones sobre edge***************************/

/* Crea un nuevo lado. Se le debe pasar los nombres de los nodos y la capacidad
 * El flujo se inicializa en 0
 * Si ocurrio un error, retorna NULL*/
edge *edge_new (u32 nod1, u32 nod2, u32 capacity){
	edge *xy = NULL;

	xy = (edge*) malloc (sizeof(struct edgeSt));
	if (xy != NULL){
		xy->x = nod1;
		xy->y = nod2;
		xy->cap = capacity;
		xy->flow = 0;
		xy->sense = FORWARD;
	}
	/*agregar errno*/
	return xy;
}

/* Destruye un lado.
 * Pre: el edge no debe ser NULL
 */
void edge_destroy (edge *xy){
	assert(xy != NULL);
	free(xy);
	xy = NULL;
}

/*analizar el retorno
 * FALTA PROGRAMAR
 */
int increase_flow (edge xy, int flow){

}

/* Setea el sentido del edge en el que se va a correr flujo
 */
void edge_set_sense (edge *xy, flag_s FLAG){
	assert (xy != NULL);
	xy->sense = FLAG;
}


/**********************consultas sobre edge***********************************/

/* Devuelve el sentido del edge en el que se va a correr flujo
 */
flag_s edge_get_sense (edge *xy){
	assert (xy != NULL);
	return xy->sense;
}

/* Decide si el lado se encuentra saturado en el sentido consultado
 * Pre: edge != NULL y cap >= flow
 * Ret: true si el edge xy esta saturado en sentido FLAG. false sino lo esta.
*/
bool edge_saturated (edge *xy, flag_s FLAG){
	bool result = false;

	assert( xy!= NULL);
	assert(xy->flow <= xy->cap);

	/*si se consulta en sentido forward*/
	if (FLAG == FORWARD){
		if (xy->flow == xy->cap){
			result = true;
		}
	/*si se consulta en sentido backward*/
	}else if (FLAG == BACKWARD){
		if (xy->flow == 0 ){
			result = true;
		}
	}

	return result;
}



/*********************funciones sobre edArray***************************/

/* Crea un edArray. Devuelve un puntero a la estructura
 * Si ocurrio un error, retorna NULL
 */
edArray *edArray_new(){
	edArray *edarr;

	edarr = (edArray *) malloc(sizeof(struct edArray));
	if (edarr != NUL){
		edarr->counter = 0;
	}
	/*aca va un errno*/
	
	return edarr;
}

/* Destruye el edArray y las estructura que contiene
 */
void edArray_destroy (edArray *edarr){
	assert(edarr != NULL);
	
	/*Destruyo todos los edges que contiene*/
	while (edarr->counter > 0){
		edge_destroy(edarr->edges[counter-1]);
	}
	/*libero el puntero*/
	free(edarr);
	edarr = NULL;
}

/* Añade un edge al final del arreglo*/
void *edArray_add_edge (edArray *edarr, edge *xy){
	size_t new_size;
	
	assert(edarr != NULL);
	assert(xy != NULL);
	/* Se (re)alloquea el arreglo (adiciona memoria)*/
	new_size = (edarr->counter + 1) * sizeof(struct edgeSt);
	edarr->edges = (u32 *) realloc(edarr->edges, new_size);
	/* Si se pudo dar memoria, se agrega el edge*/
	if (edarr->edges != NULL){
		edarr->edges[edarr->counter] = xy;
		edarr->counter++;
	/* mayday mayday! destruir todo (o dejar como estaba???)*/
	}else{
		/*aca va un errno*/
		/*edArray_destroy(edarr);*/
	}
}

/**********************consultas sobre edArray*****************************/

/* Devuelve la cantidad de elementos de edarr
 * Pre: edarr != NULL
 */
u32 edArray_size(edArray *edarr){
	assert(edarr != NULL);
	return (edarr->counter);
}

/* Devuelve un puntero al elemento i-esimo o NULL si falla
 */
edge *edArray_item(edArray *edarr, u32 i){
	edge *xy = NULL;
	
	assert(edarr != NULL);
	if (i < edarr->counter){
		xy = edarr->edges[i];
	}
	
	return xy;
}

/* Devuelve true si esta vacio o false sino
 */
bool edArray_is_empty(edArray *edarr){
	assert(edarr != NULL);
	return (edarr->counter == 0);
}