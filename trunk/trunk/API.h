#ifndef API_H
#define API_H

typedef struct ENetwork EstadoNetworkSt;
typedef EstadoNetworkSt *EstadoNetwork;

typedef unsigned int u32;


/*
	*Aloca memoria e inicializa la estructura de datos.
	*input:Vervosidad, se usa para inicializar los campos.
	*output:puntero a la estructura o NULL en caso de error(debe imprimir un error
	*	en pantalla en caso de ser causado por el int vervosidad)
*/
EstadoNetwork networkNuevo(int Verbosidad);


/*
	*Destruye y libera un EstadoNetwork.
	*input: EstadoNetwork a liberar
	*output: ok=>!Null | error=>Null
*/
int chauNetwork(EstadoNetwork N);


/*
	*lee de un input un lado y lo agrega a EstadoNetwork con un flujo 0.
	*input: "x y c" (sin las comillas) donde el lado es xy y c es su capacidad.
	*	los valores seran u32. Si existe xy entonces no formara parte de  la 
	*	entrada el lado yx, no habra lados repetidos ni loops.
	*output: ok=>1 | error=>0
*/
int LeerUnLado(EstadoNetwork N);



/*
	*Aumenta y actualiza el flujo del EstadoNetwork. El aumento debe ser dado
	*por la busqueda de un camino aumentante y el aumento a lo largo de el.
	*Hace dos cosas distintas si existe camino aumentante.
	*Esta funcion imprime en standar output segun la vervosidad:
	*Si el flujo se puede aumentar
	*	if(vervosidad mod 10 = 0) then no se imprime nada
	*	if(vervosidad mod 10 = 1) then se imprime el valor del incremento
	*		printf("Incremento del camino aumentante #: <cantDelIncremento>")
	*		donde # es el numero del camino aumentante
	*	if(vervosidad mod 10 = 2) then se imprime el camino y su incremento
	*		printf("s,x_1,...,x_r,t: <cantDelIncremento>")
	*Si el flujo no se puede aumentar
	*	if(vervosidad=0,1,2,10,11,12) then 
	*		print("No hay mas caminos aumentantes")
	*	if(vervosidad = 100,101,102,110,111,112)then se imprime lo mismo que en 
	*		el caso anterior y tambien:
	*		printf("Corte Minimal: S = {s,x_1,...}\n")
	*		printf("Capacidad: <cantDelIncremento>")
	*input:  EstadoNetwork
	*output: aumento=>1 | no aumento=>0 | error=>-1
*/
int AumentarFlujo(EstadoNetwork N);


/*
	*imprime el flujo maximal
	*input: network
	*output: por standar output y depende de verbosidad
*/
void ImprimirFlujoMaximal(EstadoNetwork N);

#endif