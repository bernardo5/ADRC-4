#include "dijkstra.h"

int min(int i, int n){
	if(i<n){
		return i;
	}else{
		return n;
	}
	return -1;
}

int table(int u, int uv){
	if(u==4){
		return uv;
	}else{
		if(u==3){
			if(uv==3) return 3;
			if(uv==2) return 2;
			if(uv==1) return 1;
		}else{
			if(u==2){
				if(uv==3) return -4;
				if(uv==2) return -4;
				if(uv==1) return 1;
			}else{
				if(u==1){
					if(uv==3) return -4;
					if(uv==2) return -4;
					if(uv==1) return 1;
				}
			}
		}
	}
	
	
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
			Insert(h, i+1, (*node_distance), &(*heap_place), (*node_hops));
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
	int i, *heap_place, tab;
	heap_place=malloc(count_nodes*sizeof(int));
	if(heap_place==NULL)exit(-1);
	for(i=0; i<count_nodes;i++) heap_place[i]=-1;
	if(count_nodes>0){
		heap=NewHeap(count_number_nodes(list, count_nodes));
		Initialize_distance_matrix(count_nodes, &(*node_distance), &(*node_hops), list, destiny, heap, &heap_place);
		while(HeapEmpty(heap)){
			dijkstra_identifier= RemoveMax(heap, (*node_distance), &heap_place, (*node_hops));
			dijkstra_u = dijkstra_identifier - 1;
			if((*node_distance)[dijkstra_u]!=-1){
				/*for each uv*/
					for(links=(list[dijkstra_u]).link;links!=NULL; links=links->next){
						if(heap_place[(links->identifier)-1]!=-1){
							if((*node_distance)[(links->identifier)-1] <= (tab=table((*node_distance)[dijkstra_u], links->preference))){
								
									if(((*node_distance)[(links->identifier)-1])==tab){
										/*same route type, chooses the one with less hops*/
										if(((*node_hops)[(links->identifier)-1])>((*node_hops)[dijkstra_u]+1))
											(*node_hops)[(links->identifier)-1]=(*node_hops)[dijkstra_u]+1;
									}else{
										/*changed route type so just updates the number of hops*/
										(*node_hops)[(links->identifier)-1]=(*node_hops)[dijkstra_u]+1;
										//this line was outside the else
										(*node_distance)[(links->identifier)-1] = tab;
							
										
									}
									FixUp(heap, heap_place[(links->identifier)-1], (*node_distance), &heap_place, (*node_hops));					
									
								
							}		
						}			
					}
			}
		}
		invert_weights(&(*node_distance), count_nodes);	
	}
	free(heap_place);
	FreeHeap(heap);
	return;
}
