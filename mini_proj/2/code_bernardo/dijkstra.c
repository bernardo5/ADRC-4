#include "dijkstra.h"
#include "heap.h"

void Initialize_distance_matrix(int**node_identifiers, int**node_distance,/* int**node_visited,*/ node *list, int destiny){
	int i;
	node*aux;
	for(i=0, aux=list; aux!=NULL; aux=aux->next, i=i+1 ){
		(*node_identifiers)[i]=aux->identifier;
		(*node_distance)[i]=-1; /*infinity distance*/
		//(*node_visited)[i]=0; /*node not seen*/
		if((aux->identifier)==destiny){
			(*node_distance)[i]=0;
			//(*node_visited)[i]=1;
		}
	}
	return;
}



int unseen_nodes_list(int * node_visited, int colums){
	int i;
	for(i=0; i<colums;i++){
		if(node_visited[colums]==0) return 1;
	}
	return 0;
}

void Dijkstra(node*list, int destiny){
	
	int count_nodes=0;
	node*aux;
	adj_node*links;
	int dijkstra_u=0;
	for(aux=list; aux!=NULL; aux=aux->next)count_nodes=count_nodes+1;
	printf("numero de nos:%d\n\n", count_nodes);
	int colum;
	Heap *h;
	if(count_nodes>0){
		h=NewHeap(count_nodes);
		int*node_identifiers=malloc(count_nodes*sizeof(int));
		int*node_distance=malloc(count_nodes*sizeof(int));
		printf("Alocou a matriz\n");
		Initialize_distance_matrix(&node_identifiers, &node_distance, /*&node_visited,*/ list, destiny);
		printf("Analizou a matriz das distancias\n");
		//int count_nodes_cycle=count_nodes;
		//printf("numero de nos: %d\n", count_nodes);
		
		for(dijkstra_u=0; dijkstra_u<count_nodes; dijkstra_u++)printf("%d\t", node_identifiers[dijkstra_u]);
		printf("\n\n");
		
		for(dijkstra_u=0; dijkstra_u<count_nodes; dijkstra_u++)printf("%d\t", node_distance[dijkstra_u]);
		printf("\n\n");
		
		while(!HeapEmpty(h)){
			if(node_distance[dijkstra_u=RemoveMax(h, &node_distance)]!=-1){
				for(aux=list;aux->identifier!=dijkstra_u;aux=aux->next);
				
					for(links=aux->link;links!=NULL; links=links->next){
						for(colum=0; node_identifiers[colum]!=links->identifier; colum++);
						if(node_distance[colum] < max(node_distance[dijkstra_u],links->preference)){
							node_distance[colum] = max(node_distance[dijkstra_u],links->preference);
							Heapify(h, &node_distance);
						}						
					}
			}
		}		
		for(colum=0; colum<count_nodes; colum++){
			printf("%d\t%d\n", node_identifiers[colum], node_distance[colum]/*, node_visited[colum]*/);
		}
	}
	return;
}
