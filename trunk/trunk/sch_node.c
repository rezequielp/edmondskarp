#include <stdlib.h>
#include "edge.h"

void xNode_destroy (xNode *xnod);
static xNode *new_node (edge *xy, u32 n1, u32 n2, flag_s DIRECTION);
static int add_neighbor (edge *ed, u32 nod, yNode *FoBarr, u32 *counter);
static int insert_node (schArray *scharr, xNode *xnod);


/* Estructura que contiene el nodo x, un arreglo de vecinos 'y' en sentido
 * forward, y otro en sentido backward (y sus respectivos tamaños)*/
typedef struct xNodeSt{
	u32 x;
	yNode *Farr;
	yNode *Barr;
	u32 Fcounter;
	u32 Bcounter;
}xNode;

/* Estructura que contiene el vecino 'y' de 'x', y un puntero al edge conformado
 * por estos 2, que se encuentra en el arreglo de edges (edArray del programa).
 * WARNING: Este puntero al edge no se libera, es solo de referencia*/
typedef struct yNodeSt{
	u32 y;
	edge *xy;
}yNode;

/* Arreglo de 'xNods' (con estructura xNodeSt)
 * este es el arreglo principal de busqueda*/
struct schArraySt{
	xNode *xarr;
	u32 counter;
};


/* FUNCIONES */


/* Crea un nuevo arreglo de busqueda. Se inicializa la estructura
 * Si pudo alloquear memoria, devuelve un puntero al nuevo arreglo de busqueda
 * Si ocurrio error, devuelve un puntero a NULL
 */
schArray *schArray_new (){
	schArray *scharr = NULL;

	scharr = (schArray *) malloc(sizeof(struct schArraySt));
	if (scharr != NULL){
		scharr->xarr = NULL;
		scharr->counter = 0;
	}
	/*aca iria un errno*/
	return scharr;
}

/* Destruye un schArray
 */
void schArray_destroy (schArray *scharr){
	xNode *xnod = NULL;

	assert(scharr != NULL);
	while (scharr->counter > 0){
		xnod = scharr->arr[scharr->counter - 1];
		xNode_destroy(xnod);
		scharr->counter--;
	}
	free(scharr);
}

/* Agrega un edge al arreglo de busqueda.
 * Del edge se obtienen los nodos, para la busqueda por nodos; y se almacena
 * un puntero a la memoria en donde se encuentra alojado el edge
 */
int schArray_add_edge (schArray *scharr, edge *xy){
	int status = SCHARR_ERR;
	xNode *fnod = NULL; /* nuevo nodo*/
	xNode *bnod = NULL; /* nodo backward del nuevo nodo*/
	u32 x; /*nombre del nodo x*/
	u32 y; /*nombre del nodo y*/

	assert (xy != NULL);

	x = edge_get_x(xy);
	y = edge_get_y(xy);
	fnod = new_node(xy, x, y, FORWARD);
	/* Se agrega a scharr y se ubica con heap*/
	if (fnod != NULL){
		status = insert_node (scharr, fnod);
		/* Este heap no debe ordenar de menor a mayor, solo ubica los nodos
		 * como arbol binario*/
		if (status != SCHARR_ERR) heap(scharr);
	}
	/* No hubo errores y 'x' no es la fuente (s) o el resumidero (t)
	* busco a 'y' en scharr para agregarle a 'x' como su backward*/
	if (status != SCHARR_ERR && fnod->x != 0 && fnod->x != 1){
		bnod = search_node(y);
		/* Si no se encuentra, debo crearlo*/
		if (bnod == NULL){
			bnod = new_node(xy, y, x, BACKWARD);
		}
		/* Se agrega a scharr y se ubica con heap*/
		if (bnod != NULL){
			status = insert_node (scharr, bnod);
			/* Este heap no debe ordenar de menor a mayor, solo ubica los nodos
			* como arbol binario*/
			if (status != SCHARR_ERR) heap(scharr);
		}
	}

	/* En caso de error, se libera la memoria asignada*/
	if (status == SCHARR_ERR){
		if (fnod != NULL) xNode_destroy(fnod);
		if (bnod != NULL) xNode_destroy(bnod);
	}
	return status;
}


/* INTERNAS*/


/* Destruye un nodo del schArray*/
void xNode_destroy (xNode *xnod){
	yNode *ynod = NULL;

	assert(xnod != NULL);
	while (xnod->Fcounter > 0){
		ynod = xnod->Farr[xnod->Fcounter - 1];
		free(ynod);
		xnod->Fcounter--;
	}
	while (xnod->Bcounter > 0){
		ynod = xnod->Farr[xnod->Bcounter - 1];
		free(ynod);
		xnod->Bcounter--;
	}
	free(xnod);
}

/* Crea un nuevo nodo principal (xNode). Agrega su vecino segun el sentido
 * de direccion establecido. Devuelve NULL en caso de error
 */
xNode *new_node (edge *xy, u32 n1, u32 n2, flag_s DIRECTION){
	int status = SCHARR_ERR;
	xNode *xnod = NULL;

	assert (xy != NULL);
	xnod = (xNode *) malloc(sizeof(struct xNodeSt));
	/* Se guarda 'x' y se intenta agregar 'y' segun el sentido establecido*/
	if (xnod != NULL){
		xnod->x = n1;
		if (DIRECTION == FORWARD){
			status = add_neighbor(xy, n2, xnod->Farr, &xnod->Fcounter);
		}else if (DIRECTION == BACKWARD){
			status = add_neighbor(xy, n1, bnod->Barr, &bnod->Bcounter);
		}

	}
	/* se dio memoria, pero ocurrio algun otro error*/
	if (xnod != NULL && status = SCHARR_ERR) free(xnod);

	return xnod;
}

/* Agrega un vecino al arreglo Farr (Barr).
 * Devuelve un estado de error, SCHARR_ERR o SCHARR_OK
 */
int add_neighbor (edge *ed, u32 nod, yNode *FoBarr, u32 *counter){
	int status = SCHARR_ERR;
	size_t new_size;
	yNode *tmp_yNod;

	assert (ed != NULL);
	assert (FoBarr != NULL);

	new_size = (xnod->Fcounter + 1) * sizeof(struct yNodeSt);
	tmp_yNod = (yNode *) realloc(FoBarr, new_size);
	/* Si se le pudo dar mas memoria, se guarda 'y' en FoBarr*/
	if (tmp_yNod != NULL){
		FoBarr = tmp_yNod;
		FoBarr[*counter].y = nod;
		FoBarr[*counter].xy = ed;
		counter = *counter + 1;
		status = SCHARR_OK;
	}

	return status;
}

/* Insterta un nuevo nodo en el arreglo de busqueda por nodos
 * Devuelve un estado de error, SCHARR_ERR o SCHARR_OK
 */
int insert_node (schArray *scharr, xNode *xnod){
	int status = SCHARR_ERR;
	u32 new_size = 0;
	schArray *tmp_schArr;

	assert (scharr != NULL);
	assert (xnod != NULL);

	new_size = scharr->counter * sizeof(struct xNodeSt);
	tmp_schArr = (schArray *) realloc (scharr->xarr, new_size);
	if (tmp_schArr != NULL){
		scharr->xarr = tmp_schArr;
		scharr->xarr[scharr->counter] = xnod;
		scharr->counter++;
		status = SCHARR_OK;
	}

	return status;
}
