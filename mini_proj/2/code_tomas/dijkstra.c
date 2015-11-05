#include "lista_adjacencias.h"
#include "dijkstra.h"

void Initialize_distance_matrix(node*list, int *** distance, int destiny){
	
	int i;
	node*aux;
	for(i=0, aux=list;aux!=NULL;aux=aux->next, i++){
		if(aux->identifier==destiny){
			*distance[1][i]=0;
			*distance[2][i]=1; //node seen
		}else{
			*distance[1][i]=-1;
			*distance[2][i]=0; //node not seen
		}
		*distance[0][i]=aux->identifier;
	}
	return;
}

void Dijkstra(node*list, int destiny){

	node*aux;
	adj_node*links;
	int new_node;
	
	int count_nodes=0;
	for(aux=list;aux!=NULL;aux=aux->next) count_nodes++;
	
	int ** distance = (int**)malloc(3*sizeof(int*));
	int row;
	
	for(row=0;row<count_nodes;row++){
		distance[row] = (int*)malloc(count_nodes*sizeof(int));
	}
	
	Initialize_distance_matrix(list, &distance, destiny);
	
	while(count_nodes!=0){
	
		for(aux=list;aux->identifier!=destiny;aux=aux->next);		
		
		for(row=0;distance[0][row]!=aux->link->identifier;row++);
		distance[2][row]=1; //node seen
		
		new_node=aux->link->identifier;
		
		for(aux=list;aux->identifier!=new_node;aux=aux->next);	
		for(links=aux->link; links!=NULL; links=links->next){
		
		}
		
		count_nodes --;
	}
	return;
}
