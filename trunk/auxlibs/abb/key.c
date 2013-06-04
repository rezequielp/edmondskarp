#include "key.h"
#include <string.h>
#include <stdlib.h>
#include "error.h"
#include <assert.h>


#define KEY_MAX_LENGHT 25/*modificar*/

struct sKey{
	u32 key;
	int lenght;

};


int key_maxLen (void) {

	return KEY_MAX_LENGHT;
}


Key key_fromString (char *s){

	Key k;
	assert (s!=NULL);
	k = (Key) malloc (sizeof(struct sKey));
	
	if (k==NULL) 
      		err(EXIT_FAILURE, ERRFMT, "key_fromString",__LINE__);

	k->lenght = strnlen(s,key_maxLen());
	strncpy(k->key, s, k->lenght+1);

	return k;
}


void key_toString (Key k, char *s){
	assert (k!=NULL);
	assert (s!=NULL);
	strncpy (s, k->key, k->lenght+1);
}

int key_length (Key k){
	assert (k!=NULL);
	return (k->lenght);
}

bool key_eq (Key k1, Key k2){
	assert (k1!=NULL);
	assert (k2!=NULL);
	return (strncmp(k1->key, k2->key, key_maxLen()) == 0);
}

bool key_le (Key k1, Key k2){
	assert (k1!=NULL);
	assert (k2!=NULL);
	return (strncmp(k1->key, k2->key, key_maxLen()) < 0);
}


Key key_clone (Key k1){
 	assert (k1!=NULL);
	return (key_fromString(k1->key));
}


Key key_destroy (Key k){
	
	if (k!=NULL){
		free (k);
		k = NULL;
	}
	return k;
}
