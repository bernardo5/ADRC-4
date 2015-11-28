#include "ford-folkerson.h"

/*Initialize a new element on the queue*/
element* FIFONew(int number, int signal, element *pNext){
	element *x = (element *) malloc(sizeof (element));
	x->number = number;
	x->signal=signal;
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
void FIFOPut(FIFO *pFIFO, int number, int signal){
	if (pFIFO->first == NULL) { /*a fila está vazia*/
		pFIFO->last = FIFONew(number, signal, pFIFO->first);
		pFIFO->first = pFIFO->last; 
		return;
	}
	/*o item é colocado no fim da lista*/
	pFIFO->last->next = FIFONew(number, signal, NULL);
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

void init_vector_disc(disc**vector, int size){
	int i;
	for(i=0; i<size; i++){
		((*vector)[i]).minus=-1;
		((*vector)[i]).plus=-1;
	}
	return;
}


void BFS(int initial, node*list, int **parent, int size){
	element*aux_element;
	adj_node*aux_adj_node;
	disc*discovered=malloc(size*sizeof(disc));
	FIFO* fifo=FIFOInit();
	
	init_vector(&(*parent), size);
	init_vector_disc(&discovered, size);
	
	(discovered[initial]).plus=1;
	(discovered[initial]).minus=1;
	FIFOPut(fifo, initial, 1);
	
	while((fifo->first)!=NULL){
		for(aux_element = fifo->first; aux_element!=NULL ; aux_element = aux_element->next){
			if(aux_element->signal==1){ /*plus*/
				aux_adj_node = ((list)[aux_element->number]).plus;
			}else{ /*minus*/
				aux_adj_node = ((list)[aux_element->number]).minus;
			}
			while(aux_adj_node != NULL){
				if(aux_element->number==(aux_adj_node->identifier)){ /*same node*/
					if((discovered[aux_adj_node->identifier]).plus==-1){
						(discovered[aux_adj_node->identifier]).plus = 1;
						FIFOPut(fifo, aux_adj_node->identifier, 1);
					}
				}else{
					if((discovered[aux_adj_node->identifier]).minus==-1){
						(discovered[aux_adj_node->identifier]).minus = 1;
						(*parent)[aux_adj_node->identifier] = aux_element->number;
						FIFOPut(fifo, aux_adj_node->identifier, 0);
					}
				}
				aux_adj_node = aux_adj_node->next;
			}
			FIFOGet(fifo);
		}
	}
	int i;
	printf("\n parent \n");
	for(i=0;i<size;i++) printf("\t %d", (*parent)[i]);
	printf("\n");
	
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
