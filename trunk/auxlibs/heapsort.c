#include "heap.h"
#include "heapsort.h"
#include "queue.h"

queue heapsort(heap H){
	queue Q = NULL;
	Q = empty_queue();
	ElementType tmp;
	while(!IsEmpty(H)){
		tmp = FindMin(H);
		Q = enqueue(Q,tmp);
		tmp = DeleteMin(H);
	}
	H = Destroy(H);
	return Q;
}