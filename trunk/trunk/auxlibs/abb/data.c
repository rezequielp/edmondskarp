#include "data.h"
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include <assert.h>


struct sData {
	char *data;
	int lenght;
};


Data data_fromString (char *s){

	Data d;
	assert (s!=NULL);

	d = (Data) malloc (sizeof(struct sData));

	if (d==NULL)
     		err(EXIT_FAILURE, ERRFMT, "data_fromString",__LINE__);

	d->lenght = strlen(s);	
	d->data = (char*)calloc((d->lenght+1),sizeof(char));
		
	if (d->data == NULL)
		err(EXIT_FAILURE, ERRFMT, "data_fromString",__LINE__);

	strncpy(d->data, s, d->lenght+1);

	return d;
}

	

char * data_toString (Data d){

	char *c; 
	assert (d!=NULL);
    
	c = (char*) malloc ((d->lenght +1) * sizeof(char));

	if (c == NULL)
		err(EXIT_FAILURE, ERRFMT, "data_toString",__LINE__);

	strncpy(c, d->data, d->lenght +1);
	return c;
}

int data_lenght (Data d){
	assert (d!=NULL);
	return (d->lenght);
}


Data data_clone (Data d){
	assert (d!=NULL);
	return data_fromString (d->data);
}

Data data_destroy(Data d){

	if (d!=NULL){
		free(d->data);
		d->data = NULL;
		free(d);
		d = NULL;
	}
	return d;
}
