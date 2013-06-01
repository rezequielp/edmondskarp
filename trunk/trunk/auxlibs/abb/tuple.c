#include "tuple.h"
#include <stdlib.h>
#include "error.h"
#include <assert.h>

struct sTuple {
	Key key;
	Data data;
};


Tuple tuple_fromKeyData (Key k, Data d){
	
	Tuple t;
	assert (k!=NULL);
	assert (d!=NULL);

	t = (Tuple) malloc (sizeof(struct sTuple)); 
	
	if (t==NULL)
		err(EXIT_FAILURE, ERRFMT, "tuple_fromKeyData",__LINE__);     
	 
	t->key = k;
	t->data = d;

	return t;	
}


Key tuple_fst (Tuple t){
	assert (t!=NULL);
	return t->key;
}


Data tuple_snd (Tuple t){
	assert (t!=NULL);
	return t->data;
}


Tuple tuple_clone (Tuple t){
	assert (t!=NULL);
	return tuple_fromKeyData (key_clone (t->key), data_clone (t->data));
}


Tuple tuple_destroy(Tuple t){
	
	if (t!=NULL){
		t->key = key_destroy(t->key);
		t->data = data_destroy(t->data);
		free (t);
	}
	return t;
}

