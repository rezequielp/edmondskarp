#include "abb.h"
#include "assert.h"
#include "error.h"
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include "cr.h"
#include "cw.h"
#include <math.h>


#define Leaf ((Tree) NULL)

static void impr(Tree t, char *k);
static void balance (Abb h, Stack s);
static int factor_equil(Tree t);
static void alt_update(Tree t);
static Tree s_rotate(Tree t, bool rgt);
static Tree d_rotate(Tree t, bool rgt);


struct sAbb {
	int cant;
	Tree tree;
};

struct Branch {
	int alt;
	Key k; 
	Data d;
	Tree l, r;
};


Abb abb_empty (void){
	Abb h;
	h = (Abb) malloc (sizeof (struct sAbb));
	if (h==NULL)
     		err(EXIT_FAILURE, ERRFMT, "abb_empty",__LINE__);
	h->cant = 0;
	h->tree = Leaf;
	return h;
}

void abb_add (Abb h, Key ke, Data d){
	Tree *t;
	Stack s;
	assert(h!=NULL);
	assert(ke!=NULL);
	assert(d!=NULL);
	t=&(h->tree);
	s=stk_empty();
	if((*t)!=Leaf){		
		while(!((*t)==Leaf)){
			stk_push(*t,s);
			if(key_le(ke,(*t)->k))
				t=&((*t)->l);
			else
				t=&((*t)->r);
		}
	}
	*t = (Tree)malloc(sizeof(struct Branch));
	if ((*t)==NULL)
		err(EXIT_FAILURE, ERRFMT, "abb_add",__LINE__);
	(*t)->k = ke;
	(*t)->d = d;
	(*t)->l = Leaf;	
	(*t)->r = Leaf;
	(*t)->alt = 0;
	h->cant++;
	balance(h,s);
	s=stk_destroy(s);
}

bool abb_exists (Abb h, Key ke){
	Tree t;
	assert(h!=NULL);
	assert(ke!=NULL);
	t = h->tree;
	while (t!=Leaf && !key_eq(ke, t->k)){	
		if (key_le (ke, t->k))
			t = t->l;
		else
			t = t->r;	
	}
	return (t!=Leaf);
}

/* busca un dato segun la clave
debe llamarse solo si abb_exists (l, k)   
si no lo encuentra devuelve NULL */
Data abb_search (Abb h, Key ke){
	Data da;
	Tree t;
	assert(h!=NULL);
	assert(ke!=NULL);
	da=NULL;
	t=h->tree;
	while(t!=Leaf && !key_eq(t->k,ke)){
		if(key_le(ke,t->k))
			t=t->l;
		else
			t=t->r;
	}
	if(t!=Leaf)
		da=t->d;
	return da;
}

/* borra la clave y el valor asociado */
void abb_del (Abb h, Key ke){
	Tree t,q; /*t apunta al elem a eliminar. q apunta al padre adoptivo*/
	Tree *s; /* s guarda la direccion de la celda de memoria en la que se apunta al elemento a eliminar (brazo izq o der del abuelo)*/
	Stack w;/*recorrido de t para despues balancear*/
	assert(h!=NULL);
	assert(ke!=NULL);
	t=h->tree;/*el primer candidato a ser borrado*/
	s=&(h->tree); /*el primer candidato a ser borrado es la raiz. el puntero que apunta a la raiz es h->tree*/
	w=stk_empty();
	while(t!=Leaf && !key_eq(t->k,ke)){ /*busca elemento a borrar*/
		stk_push(t,w);
		if(key_le(ke,t->k)){			
			s=&(t->l);			
			t=t->l;
		}
		else{
			s=&(t->r);
			t=t->r;
		}
	}
	if(t->l!=Leaf){/*tiene rama izq*/
		q=t->l;			
		stk_push(q,w);		
		if(t->r!=Leaf){
			if(q->r!=Leaf){/*tiene rama izq y der.*/
				while( q->r->r!=Leaf){/*busco el mayor de la parte izq*/
					q=q->r;
					stk_push(q,w);
				}
				*s=q->r;/*intercambio los nodos: el mayor ocupa el lugar del elem a eliminar y adopta sus hijos*/
				q->r=q->r->l;
				(*s)->l=t->l;
			}
			else/*el hijo izq no tiene rama der. Entonces se sube q*/
				*s=t->l;
			(*s)->r=t->r; /*el nuevo padre adopta el hijo der del elemento a eliminar */		
		}
		else/*tiene rama izq pero no der. Entonces se sube el hijo der*/
			*s=q; 
	}
	else /* no tiene rama izq. Entonces se sube el hijo der, aun siendo Leaf*/
		*s=t->r;
	t->k=key_destroy(t->k);				
	t->d=data_destroy(t->d);
	free(t);
	h->cant--;
	balance(h,w);
	w=stk_destroy(w);
}

/* devuelve la cantidad de elementos */
int abb_length (Abb h){
	assert(h!=NULL);
	return (h->cant);
}

/* Lee un abb desde un archivo*/
Abb abb_fromFile(char *nomfile){
	cr c;
	Abb h;
	Tuple t;
	assert (nomfile!=NULL);

	h = abb_empty();
	c = cr_create(nomfile);

	if(c != NULL){
		cr_arr(c);
		while (!cr_fin(c)){
			t=cr_elec(c);
			if (abb_search(h, tuple_fst(t))==NULL)
				abb_add(h,tuple_fst(t), tuple_snd(t));
			cr_av(c);	/*avanzar de cr destruye la tupla anterior de vis*/
			free(t);	/*solo libero puntero t*/
		}
		c = cr_destroy(c);
	}
	else{
		h=abb_destroy(h);
	}
	return h;
}

/* Graba un abb a un archivo */
void abb_toFile(char *nomfile, Abb h){
	cw w;
	Stack s;
	Tuple t;
	assert (h!=NULL);
	assert (nomfile!=NULL);
	s=stk_empty();
	w=cw_create(nomfile);
	cw_arr(w);
	stk_push(h->tree,s);
	while (!stk_isEmpty(s)){
		t= tuple_fromKeyData (stk_top(s)->k,stk_top(s)->d);
		cw_ins(w,t);
		if (stk_top(s)->l!=Leaf)
			stk_bpush(stk_top(s)->l,s);
		if (stk_top(s)->r!=Leaf)
			stk_bpush(stk_top(s)->r,s);
		s=stk_pop(s);
		free(t);
	}
	w = cw_destroy(w);
	s=stk_destroy(s);
}

/* imprime todos los pares (Key, Data) en el arbol */
void abb_pprint (Abb h){
	Tree t;
	int i;
	char *ke;
	Key cache; /*ultimo elemento impreso*/	
	Stack s;
	assert (h!=NULL);
	s=stk_empty();	
	t=h->tree;
	i=h->cant;
	ke = (char *) malloc (key_maxLen() * sizeof(char));
	if (ke==NULL)
     		err(EXIT_FAILURE, ERRFMT, "abb_pprint",__LINE__);
	if (t!=Leaf){ /*si el arbol no es vacio*/
		while(t->l!=Leaf){ /*posiciono t en el min del arbol*/
			stk_push(t,s);
			t=t->l;
		}
		impr(t, ke);
		cache=t->k;
		i--;
	}
	while(i>0){ /* i es la cant de elem por imprimir*/
		if(t->l!=Leaf){	/*si cache>=t->l => imprimo t y me muevo a t->r ó al sig sub/meta arbol. Es decir, si ya agregue el elem mas grande de la parte izq de t, entonces subo a un nodo padre ó bajo hacia el hijo derecho*/ 
			if (!key_le(cache, t->l->k)){/*si esto pasa quiere decir que t no fue impreso*/
				impr(t, ke);
				cache=t->k;
				i--;
				if(t->r!=Leaf)
					t=t->r;
				else{
					if(i>0){
						assert(!stk_isEmpty(s));
						t=stk_top(s);
						s=stk_pop(s);
					}		
				}
			}
			else {
				stk_push(t,s);
				t = t->l;
			}
		}					
		else if(t->l==Leaf){ /*t es menor. Luego, si chache<t => imprimo t.*/
			if (key_le(cache, t->k)){
				impr(t, ke);
				cache=t->k;
				i--;
			}
			if((t->r==Leaf || !key_le(cache, t->r->k)) && i>0){
				assert(!stk_isEmpty(s));
				t=stk_top(s);
				s=stk_pop(s);		
			}
			else{
				t=t->r;			
			}
		}
	}
	free(ke);
	s=stk_destroy(s);
}

/* Destructor. Destruye todo el abb y su contenido */
Abb abb_destroy(Abb h){
	Tree t;
	int i;
	Stack s;
	s=stk_empty();
	if(h!=NULL){
		t=h->tree;
		i=h->cant;		
		while(i>0){ /* i es la cant de elem por borrar*/
			if(t->l!=Leaf){/*t se guarda en el Stack y nos movemos a t->l*/
				stk_push(t,s);			
				t=t->l;
				stk_top(s)->l=Leaf;
			}					
			else { 
				if(t->r!=Leaf){/*t se guarda en el Stack y nos movemos a t->r si existe*/
					stk_push(t,s);			
					t=t->r;
					stk_top(s)->r=Leaf;
				}
				else{ /* si t->l y t->r no existe => destruyo t*/
					t->k=key_destroy(t->k);				
					t->d=data_destroy(t->d);
					free(t);
					i--;
					if(i>0){/*si quedan elem por borrar, sigo sacando elem del Stack (candidato a borrar)*/
						assert(!stk_isEmpty(s));
						t=stk_top(s);
						s=stk_pop(s);
					}
				}
			}
		}
		free(h);
		h=NULL;
	}	
	s=stk_destroy(s);
	return h;
}
	

/*i es random*/
void abb_randomize(Abb h){
	Tree *nodos; /*piso todo el arbol en un arreglo*/
	Stack s; /*uso una pila para recorrer el arbol y poder pasarlo al arreglo*/
	char *ke; /*se usa para impr*/
	int q;/*q es la posicion del arreglo en donde agrego un nuevo elemento*/
	long int j,i; /*j es la cantidad de palabras a buscar. i es la palabra azarosa q imprimo*/
	assert (h!=NULL);
	nodos=(Tree*)malloc(h->cant*sizeof(Tree));	
	if (nodos==NULL)
     		err(EXIT_FAILURE, ERRFMT, "abb_randomize",__LINE__);
	s=stk_empty();
	ke=(char *) malloc (key_maxLen() * sizeof(char));
	if (ke==NULL)
     		err(EXIT_FAILURE, ERRFMT, "abb_randomize",__LINE__);
	j=0;
	i=0;
	q=0;	
	stk_push(h->tree,s);
	while (!stk_isEmpty(s)){ /*paso todos los nodos del arbol al arreglo*/
		if (stk_top(s)->l!=Leaf)
			stk_bpush(stk_top(s)->l,s);
		if (stk_top(s)->r!=Leaf)
			stk_bpush(stk_top(s)->r,s);
		nodos[q]=stk_top(s);
		s=stk_pop(s);
		q++;
	}	
	if (h->cant!=0) /*randomiso la cantid de palabras a buscar*/
		j=random()%(h->cant);
	printf("se van a imprimir %li palabras aleatorias\n\n",j);		
	while(j>0){
		i=random()%(h->cant); /*busco una palabra al azar dentro del arreglo*/
		if(nodos[i]!=NULL){ /*si esa palabra no fue impresa, entonces la imprimo y le asigno null en el arreglo para q no se repita*/
			impr(nodos[i],ke);
			nodos[i]=NULL;
			j--;
		}
	}
	s=stk_destroy(s);
	free(nodos);
	free(ke);
}

/***********************************************FUNCIONES LOCALES*****************************************************/	

void impr(Tree t, char *ke){
	char *da;
	assert(t!=NULL);
	assert(ke!=NULL);	
	key_toString(t->k, ke);
	da = data_toString (t->d);
	printf("%s:%s\n", ke, da);
	/*printf("           %i\n",t->alt);*/ /*PREGUNTARRRRRRRRRRRRRRRRR*/
	free(da);
}

void balance (Abb h, Stack s){
	Tree t; 
	Tree q;
	int fe;
	assert(h!=NULL);
	assert(s!=NULL);
	q=h->tree;
	while(!stk_isEmpty(s)){		
		t=stk_top(s);	
		s=stk_pop(s);
		if(!stk_isEmpty(s))
			q = stk_top(s);
		alt_update(t);
		fe=factor_equil(t);
		if(fe==2){
			if(factor_equil(t->r)==1){
				if(!stk_isEmpty(s)){
					if (key_le(q->k, t->k))
						q->r=s_rotate(t,false);
					else						
						q->l=s_rotate(t,false);
				}
				else
					h->tree=s_rotate(t,false);
			}
			else{
				if(!stk_isEmpty(s)){
					if (key_le(q->k, t->k))
						q->r=d_rotate(t,false);
					else
						q->l=d_rotate(t,false);
				}
				else
					h->tree=d_rotate(t,false);
			}
		}
		if(fe==-2){
			if(factor_equil(t->l)==-1){
				if(!stk_isEmpty(s)){
					if (key_le(q->k, t->k))
						q->r=s_rotate(t,true);
					else
						q->l=s_rotate(t,true);
				}
				else
					h->tree=s_rotate(t, true);
			}
			else{
				if(!stk_isEmpty(s)){
					if (key_le(q->k, t->k))
						q->r=d_rotate(t, true);
					else
						q->l=d_rotate(t, true);
				}
				else
					h->tree=d_rotate(t, true);
			}
		}
	}
}

int factor_equil(Tree t){
	int i;
	assert(t!=NULL);
	i=0;
	 /*si algun hijo es Leaf, entonces se concidera la altura del Leaf=(-1)*/
	/*FE=H(t->d)-H(t->l)*/
		if (t->r!=Leaf)
			i=t->r->alt;
		else
			i=-1;

		if (t->l!=Leaf)
			i=i-t->l->alt;
		else
			i= i-(-1);
	
	return i;
}

Tree s_rotate(Tree t, bool rgt){/*soluciona un desequilibro izq-izq o der-der*/
	
	Tree k;
	assert(t!=NULL);
	if(rgt){/*rotacion de un nodo de la izq del padre, hacia la derecha del arbol*/
		k=t->l;
		t->l=k->r;
		k->r=t;
	}
	else{/*rota hacia la izq del arbol*/
		k=t->r;
		t->r=k->l;
		k->l=t;
	}
	alt_update(t);
	alt_update(k);
	return k;
}

Tree d_rotate(Tree t, bool rgt){/*soluciona un desequilibrio izq-der o der-izq*/
	assert(t!=NULL);	
	if(rgt){
		t->l = s_rotate(t->l,false);/*lleva el desequilibrio izq-der a uno de la forma izq-izq*/
		t = s_rotate(t,true);/*soluciona un desequilibro izq-izq*/
	}
	else{
		t->r = s_rotate(t->r,true);/*lleva el desequilibrio der-izq a uno de la forma der-der*/
		t = s_rotate(t,false);/*soluciona un desequilibro der-der*/
	}
	return t;
}

void alt_update(Tree t){
	assert(t!=NULL);
	if(t->r!=Leaf && t->l!=Leaf)
		t->alt=1+fmax(t->l->alt,t->r->alt);
	else{
		if (t->r==Leaf){
			if(t->l==Leaf)
				t->alt=0;
			else
				t->alt=1+t->l->alt;
		}
		else
			t->alt=1+t->r->alt;
	}
}

