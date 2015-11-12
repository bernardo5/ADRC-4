#include "dijkstra.h"

int min(int i, int n){
	if(i<n){
		return i;
	}else{
		return n;
	}
	return -1;
}

void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, Heap*h, int**heap_place){
	int i;
	for(i=0; i<count_nodes; i++ ){
		(*node_distance)[i]=-1; /*infinity distance*/
		(*node_hops)[i]=50000;
		if((i+1)==destiny){
			(*node_distance)[i]=4;
			(*node_hops)[i]=0;
		}
		if((list[i].link)!=NULL) /*the node exists*/
			Insert(h, i+1, (*node_distance), &(*heap_place));
	}	
	return;
}

void invert_weights(int**node_distance, int count_nodes){
	int i;
	for(i=0; i<count_nodes;i++){
		if((*node_distance)[i]==1){
			 (*node_distance)[i]=3;
		}else{
			if((*node_distance)[i]==3) (*node_distance)[i]=1;
		}
	}
	
}

void Dijkstra(node*list, int destiny, int count_nodes, int**node_distance, int**node_hops){
	adj_node*links;
	int dijkstra_u=0;
	int dijkstra_identifier;
	Heap*heap;
	int i, *heap_place;
	heap_place=malloc(count_nodes*sizeof(int));
	for(i=0; i<count_nodes;i++) heap_place[count_nodes]=-1;
	if(count_nodes>0){
		heap=NewHeap(count_number_nodes(list, count_nodes));
		Initialize_distance_matrix(count_nodes, &(*node_distance), &(*node_hops), list, destiny, heap, &heap_place);
		while(HeapEmpty(heap)){
							/*int i;
							printf("heap\n");
							for(i=0; i<(h)->n_elements; i++)printf("%d\t", ((h)->heapdata)[i]);
							printf("\n\n");*/
			dijkstra_identifier= RemoveMax(heap, (*node_distance), &heap_place);
			//printf("node:%d position %d in heap\n", dijkstra_identifier, (heap_place)[dijkstra_identifier-1]);
    /* printf("heap after remove\n");*/
			/*int nm;*/
			/*for(nm=0; nm<11;nm++){
				printf("%d\t", nm+1);
			}
			for(nm=0; nm<11;nm++){
				printf("%d\t", heap_place[nm]);
			}*/
			/*printf("\n\n");*/
			dijkstra_u = dijkstra_identifier - 1;
			//unvisited_nodes[dijkstra_u]=1;
			if((*node_distance)[dijkstra_u]!=-1){
				/*for each uv*/
					for(links=(list[dijkstra_u]).link;links!=NULL; links=links->next){
						if(heap_place[(links->identifier)-1]!=-1){
							if(((*node_distance)[(links->identifier)-1] < min((*node_distance)[dijkstra_u],links->preference))&&
								((links->preference)<=(*node_distance)[dijkstra_u])){
								(*node_distance)[(links->identifier)-1] = min((*node_distance)[dijkstra_u],links->preference);
								(*node_hops)[(links->identifier)-1]=(*node_hops)[dijkstra_u]+1;
								FixUp(heap, heap_place[(links->identifier)-1], (*node_distance), &heap_place);
							}		
						}			
					}
			}
		}
		invert_weights(&(*node_distance), count_nodes);	
	}
	free(heap_place);
	return;
}
