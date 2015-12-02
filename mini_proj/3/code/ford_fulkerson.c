#include "ford_fulkerson.h"

/*Initialize a new element on the queue*/
element* FIFONew(int number, int signal, element *pNext){
	element *x = (element *) malloc(sizeof (element));
	x->number = number;
	x->signal=signal;
	x->next = pNext;
	return x; 
}

/*create a new FIFO*/
FIFO * FIFOInit(){		
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

void init_vector(int ** vector, int size, int parameter){

	int i;

	for(i=0;i<size;i++) (*vector)[i] = parameter;
	
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


disc * BFS(node * list, int initial_node, int ** parent, int size){
	
	disc * discovered = malloc(size*sizeof(disc));
	
	FIFO * fifo = FIFOInit();
	
	init_vector_disc(&discovered, size);
	init_vector(&(*parent), size, -1);
	
	(discovered[initial_node]).plus=1;
	(discovered[initial_node]).minus=1;
	FIFOPut(fifo, initial_node, 1);

	element * aux_element;
	adj_node * aux_adj_node;
	
	while(fifo->first != NULL){
		
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
					if((discovered[aux_adj_node->identifier]).minus==-1){ //if node isn't discovered
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
	
	return discovered;
	
}

int path(int initial_node, int final_node, int * parent){
	
	int path = 0;
	int i = final_node;
	
	while(parent[i]!=-1){
		i = parent[i];
	}

	if(i==initial_node) path=1;
	
	return path;
}

int ford_fulkerson(node ** list, int size, int ** parent, int initial_node, int final_node, char ** connectivity, int * min){
	
	int i;
	adj_node * aux_adj_node;

	disc * discovered = BFS((*list), initial_node, &(*parent), size);

	while(path(initial_node, final_node, (*parent))){
		
		i = final_node;
		
		while((*parent)[i]!=-1){
			
			//if not exists link from u- to u+
			if((*list)[i].minus==NULL){
				
				//remove from list plus
				//first of the list
				if((*list)[i].plus->identifier==i) (*list)[i].plus = (*list)[i].plus->next;
				//middle of the list
				else{
					for(aux_adj_node=(*list)[i].plus; aux_adj_node->next!=NULL && aux_adj_node->next->identifier!=i; 
																		aux_adj_node=aux_adj_node->next);
					aux_adj_node->next=aux_adj_node->next->next;
				}
				
				//insert in list minus
				create_link_entry_same(&(*list), i);

			//if not exists link from u+ to u-
			}else{
			
				//insert in list plus
				create_link_entry(&(*list), i, i);
				
				//remove from list minus
				(*list)[i].minus = NULL;
			}
			i = (*parent)[i];
		}
		discovered = BFS((*list), initial_node, &(*parent), size);	
	}
	
	int d;
	
	int count_nodes=0;
	char buffer[4];
	
	for(d=0;d<size;d++){
		
		//IF NODE IS SPLITTING THE GRAPH
		if((discovered[d]).minus != (discovered[d]).plus){
			count_nodes ++;
		} 
	}
	
	if(count_nodes < (*min)){
		
		(*min) = count_nodes;
		
		//ADD TO NODES NEEDED TO SPLIT GRAPH
		bzero((*connectivity), 100);
		
		for(d=0;d<size;d++){
			
		//IF NODE IS SPLITTING THE GRAPH
			if((discovered[d]).minus != (discovered[d]).plus){
				strcat((*connectivity), " ");
				sprintf(buffer, "%d", d);
				strcat((*connectivity), buffer);
				bzero(buffer, 4);
			} 
		}
	}
	
	return count_nodes;
}
