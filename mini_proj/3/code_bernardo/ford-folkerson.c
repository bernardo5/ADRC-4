#include "ford-folkerson.h"

/*Initialize a new element on the queue*/
element* FIFONew(int number, element *pNext){
	element *x = (element *) malloc(sizeof (element));
	x->number = number;
	x->next = pNext;
	return x; 
}

/*create a new FIFO*/
FIFO* FIFOInit(){		
	FIFO *pFIFO = (FIFO*) malloc(sizeof(F));
	pFIFO->first = pFIFO->last = NULL;
	return pFIFO; 
}

/*puts a new element on the queue*/
void FIFOPut(FIFO *pFIFO, int number){
	if (pFIFO->first == NULL) { /*a fila está vazia*/
		pFIFO->last = FIFONew(number, pFIFO->first);
		pFIFO->first = pFIFO->last; 
		return;
	}
	/*o item é colocado no fim da lista*/
	pFIFO->last->next = FIFONew(number, NULL);
	pFIFO->ultimo = pFIFO->last->next;
	return
}

/*Removes first FIFO element*/

int FIFOGet(FIFO *pFIFO){
	int number = pFIFO->first->number;
	element *elem = pFIFO->first->next;
	free(pFIFO->first);
	pFIFO->first= elem;
	return number; 
} 

void init_vector(int**vector, int size){
	int i;
	for(i=0; i<size; i++)(*vector)[i]=-1;
	return;
}


void BFS(int initial, node*list, int **parent, int size){
	int*discovered=malloc(size*sizeof(int));
	FIFO* fifo=FIFOInit();
	
	init_vector(&(*parent), size);
	init_vector(&discovered, size);
	
	discovered[initial]=1;
	
	
	
	return;
}
