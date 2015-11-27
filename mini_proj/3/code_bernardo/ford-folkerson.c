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
	FIFO *pFIFO = (FIFO*) malloc(sizeof(FIFO));
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
	pFIFO->last = pFIFO->last->next;
	return;
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
	element*aux_element;
	adj_node*aux_adj_node;
	int*discovered=malloc(size*sizeof(int));
	FIFO* fifo=FIFOInit();
	
	init_vector(&(*parent), size);
	init_vector(&discovered, size);
	
	discovered[initial]=1;
	FIFOPut(fifo, initial);
	
	while((fifo->first)!=NULL){
		for(aux_element = fifo->first; aux_element!=NULL ; aux_element = aux_element->next){
			for(aux_adj_node = ((list)[aux_element->number]).plus; aux_adj_node != NULL; aux_adj_node = aux_adj_node->next){
				if(discovered[aux_adj_node->identifier]==-1){
					discovered[aux_adj_node->identifier] = 1;
					(*parent)[aux_adj_node->identifier] = aux_element->number;
					FIFOPut(fifo, aux_adj_node->identifier);
				}
			}
			FIFOGet(fifo);
		}
	}
	
	
	return;
}

int path(int * parent, int initial_node, int final_node){
	int path=0;
	int i=final_node;
	while(parent[i]!=-1){
		i=parent[i];
	}
	if(i==initial_node) path=1;
	return path;
}
