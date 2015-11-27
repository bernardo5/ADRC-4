#include "ford_fulkerson.h"

void init_vector(int ** vector, int size){

	int i;
	
	for(i=0;i<size;i++) (*vector)[i]=-1;
	return;
	
}


void BFS(node * list, int initial_node, int ** parent, int size){
	
	int * discovered = malloc(size*sizeof(int));
	
	init_vector(&discovered, size);
	init_vector(&(*parent), size);
	
	discovered[initial_node] = 1;
	
	F * queue;
	element aux_element;
	node * aux_node;
	adj_node * aux_adj;
	
	while(FIFO!empty){
		
		for(aux_element = first; aux_element!=NULL ; aux_element = aux_element->next){
			aux_node = (*list)[aux_element->identifier];
			
			for(aux_adj_node = aux_node.plus; aux_adj_node != NULL; aux_adj_node = aux_adj_node->next){
				
				if(discovered[aux_adj_node->identifier]==-1){
					
					discovered[aux_adj_node->identifier] = 1;
					(*parent)[aux_adj_node->identifier] = aux_element->identifier;

					//insert node aux_adj_node->identifier in fifo queue
					
				}
			}
			//take node aux_node->identifier from fifo queue
		}
	}
	
	
	
	
	/*int i;
	for(i=0;i<size;i++) printf("%d %d %d\n", i, discovered[i], (*parent)[i]);*/
	
}
