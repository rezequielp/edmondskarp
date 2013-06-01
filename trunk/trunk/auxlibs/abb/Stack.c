#include "Stack.h"
#include <stdlib.h>
#include "error.h"
#include <assert.h>

typedef struct sNode *node;

struct sStack{
	node fst;
	node lst;
};

struct sNode{
	alpha elem;
	node tail;
};

Stack stk_empty(void){
	Stack s;
	s=(Stack)malloc(sizeof(struct sStack));
	if (s==NULL)
     		err(EXIT_FAILURE, ERRFMT, "stk_empty",__LINE__);
	s->fst=NULL;
	s->lst=NULL;
	return s;
}

void stk_push(alpha e, Stack s){
	node r;
	assert(s!=NULL);
	r = (node) malloc(sizeof (struct sNode));
	if (r==NULL)
     		err(EXIT_FAILURE, ERRFMT, "stk_push",__LINE__);
	r->elem = e;
	r->tail = s->fst;
	s->fst = r;
	if (s->lst==NULL)
		s->lst=r;
}

bool stk_isEmpty(Stack s){
	assert(s!=NULL);
	return (s->fst == NULL);
}

alpha stk_top(Stack s){
	assert(s!=NULL);
	return s->fst->elem;
}

Stack stk_pop(Stack s){
	node r;
	assert(s!=NULL);
	r = s->fst;
	s->fst = s->fst->tail;
	free(r);
	if(s->fst==NULL)
		s->lst=NULL;
      return s; 
}

Stack stk_destroy(Stack s){
	
	if (s!=NULL){
		while (s->fst!=NULL)
			s=stk_pop(s);
		free(s);
		s=NULL;
	}
	return s;
}

void stk_bpush (alpha e, Stack s){
	node r;
	assert(s!=NULL);
	if (s->lst==NULL)
		stk_push(e,s);
	else{
		r = (node) malloc(sizeof (struct sNode));
		if (r==NULL)
	     		err(EXIT_FAILURE, ERRFMT, "stk_bpush",__LINE__);
		r->elem=e;
		r->tail=NULL;
		s->lst->tail=r; 
		s->lst=r;
	}
}
