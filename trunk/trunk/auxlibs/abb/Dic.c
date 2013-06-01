#include "Dic.h"
#include "abb.h"
#include <stdlib.h>
#include "error.h"
#include <assert.h>



struct sDict {
	Abb ab;
};



Dict dict_empty (void){
	
	Dict d;
	d = (Dict) malloc (sizeof(struct sDict)); 
     	if (d==NULL)
      		err(EXIT_FAILURE, ERRFMT, "dict_empty",__LINE__);
	if (d != NULL)     
		d->ab = abb_empty(); 
     	return d;  
}

void dict_add (Dict d, Word w, Def f){
	Key k;
	Data s;
	assert(d!=NULL);
	assert(w!=NULL);
	assert(f!=NULL);
	if (!dict_exists(d, w)){           
		k = key_fromString(w);
		s = data_fromString(f);
		abb_add (d->ab, k, s);
	}
}



bool dict_exists (Dict d, Word w){
	bool b;
	Key k;

	assert(d!=NULL);
	assert(w!=NULL);

	k = key_fromString (w);
	b = abb_exists(d->ab, k);
	k = key_destroy (k); 

	return b;
}



Def dict_search (Dict d, Word w){
	Def def;
	Data s;
	Key k;
	def = NULL;

	assert(d!=NULL);
	assert(w!=NULL);


	if (dict_exists(d, w)){
		k = key_fromString (w);		
		s = data_clone (abb_search (d->ab , k));	
		def = data_toString (s);
		k = key_destroy (k);
		s = data_destroy (s);
	}
	return def;
}


void dict_del (Dict d, Word w){
	assert(d!=NULL);
	assert(w!=NULL);
	if (dict_exists(d, w)){  
		Key k;
     		k = key_fromString (w);         
     		abb_del(d->ab, k);
     		k = key_destroy (k);  
	}
}



void dict_pprint (Dict d){
	assert(d!=NULL);
	abb_pprint (d->ab);
}


int dict_length (Dict d){
	assert(d!=NULL);
	return abb_length(d->ab);
}


Dict dict_destroy (Dict d){
	if (d!=NULL){	
		d->ab = abb_destroy(d->ab);
		free(d);	
		d = NULL;
	}
	return d;
}

int word_maxlen(void){
	return key_maxLen();	
}

Dict dict_fromFile(char *f){
	Dict d;
	assert(f!=NULL);

	d = (Dict) malloc (sizeof(struct sDict));
	if (d==NULL)
      		err(EXIT_FAILURE, ERRFMT, "dict_fromFile",__LINE__);
	
	d->ab = abb_fromFile(f);
	if (d->ab==NULL)
		d=dict_destroy(d);
	return d;
}

void dict_toFile(char *f, Dict d){
	assert(f!=NULL);
	assert(d!=NULL);	
	if (d->ab!=NULL)
		abb_toFile(f,d->ab);
}

void dict_randomize(Dict d){
	assert(d!=NULL);
	if (d->ab!=NULL)
		abb_randomize(d->ab);
}
