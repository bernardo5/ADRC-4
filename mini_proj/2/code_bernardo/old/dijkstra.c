#include "dijkstra.h"

int min(int i, int n){
	if(i<n){
		return i;
	}else{
		return n;
	}
	return -1;
}


/*inserts a node in the dijkstra queue*/
void insert(int identifier, dij_node**list){
	dij_node *n;
	n=(dij_node*)malloc(sizeof(dij_node));
	n->identifier=identifier;
	n->next=(*list);
	(*list)=n;
	return;
}

int empty_queue(dij_node*visited_nodes){
	if(visited_nodes==NULL) return 0;
	return 1;
}

int identifier_smaller_distance(int**heap_place, node*list, int*node_distance, int*node_hops, int count_nodes, dij_node**visited_nodes){
	int node_id;
	int dist=-4;
	int hops=50001;
	dij_node*aux_remove, *aux_remove_ant;
	dij_node*aux=(*visited_nodes);
	dij_node*aux_ant;
	/*last element*/
	if((*visited_nodes)->next==NULL){
		node_id=(*visited_nodes)->identifier;
		(*heap_place)[node_id-1]=-1;
		aux_remove=(*visited_nodes);
		free(aux_remove);
		(*visited_nodes)=NULL;
		return node_id;
	}else{
		/*start with first element*/
		dist=node_distance[((*visited_nodes)->identifier)-1];
		hops=node_hops[((*visited_nodes)->identifier)-1];
		node_id=((*visited_nodes)->identifier);
		
		for(aux_ant=(*visited_nodes), aux=aux_ant->next; aux!=NULL; aux_ant=aux_ant->next, aux=aux->next){
			if(node_distance[(aux->identifier)-1]>=dist){
				if(node_hops[(aux->identifier)-1]<hops){
					dist=node_distance[(aux->identifier)-1];
					hops=node_hops[(aux->identifier)-1];
					aux_remove=aux;
					aux_remove_ant=aux_ant;
					node_id=(aux->identifier);
				}
			}
		}
		(*heap_place)[node_id-1]=-1;
		if(node_id!=((*visited_nodes)->identifier)){
			aux_remove_ant->next=aux_remove->next;
		}else{
			aux_remove=(*visited_nodes);
			(*visited_nodes)=(*visited_nodes)->next;
		} 
		free(aux_remove);
		return node_id;
	}
}

void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, dij_node ** visited_nodes, int**heap_place){
	int i;
	for(i=0; i<count_nodes; i++ ){
		(*node_distance)[i]=-1; /*infinity distance*/
		(*node_hops)[i]=50000;
		if((i+1)==destiny){
			(*node_distance)[i]=4;
			(*node_hops)[i]=0;
		}
		if((list[i].link)!=NULL) /*the node exists*/
			insert(i+1, &(*visited_nodes));
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
	dij_node*visited_nodes=NULL;
	int dijkstra_u=0;
	int dijkstra_identifier;
	int i, *heap_place;
	heap_place=malloc(count_nodes*sizeof(int));
	for(i=0; i<count_nodes;i++) heap_place[i]=1;
	if(count_nodes>0){
		Initialize_distance_matrix(count_nodes, &(*node_distance), &(*node_hops), list, destiny, &visited_nodes, &heap_place);
		/*dij_node*aux;
		for(aux=visited_nodes; aux!=NULL; aux=aux->next) printf("%d\t", aux->identifier);
		printf("\n\n");*/
		while(empty_queue(visited_nodes)){
			dijkstra_identifier= identifier_smaller_distance(&heap_place, list, (*node_distance), (*node_hops), count_nodes, &visited_nodes);//RemoveMax(heap, (*node_distance), &heap_place);
			//printf("removed %d from queue\n", dijkstra_identifier);
			
			/*printf("removed list\n");
			for(i=0; i<count_nodes;i++)printf("%d\t", heap_place[i]);
			printf("\n\n");
			
			printf("costs\n");
			for(i=0; i<count_nodes;i++)printf("%d\t", (*node_distance)[i]);
			printf("\n\n");*/
			
			
		/*	printf("queue is:\n");
			for(aux=visited_nodes; aux!=NULL; aux=aux->next) printf("%d\t", aux->identifier);
			printf("\n\n");*/
			
			dijkstra_u = dijkstra_identifier - 1;
			if((*node_distance)[dijkstra_u]!=-1){
				/*for each uv*/
					for(links=(list[dijkstra_u]).link;links!=NULL; links=links->next){
						if(heap_place[(links->identifier)-1]!=-1){
							if(((*node_distance)[(links->identifier)-1] <= min((*node_distance)[dijkstra_u],links->preference))&&
																				((links->preference)<=(*node_distance)[dijkstra_u])){	
								/*if it is a consecutive peer route, the route is not usable*/
								if(!(((*node_distance)[dijkstra_u]==2)&&((links->preference)==2))){
									
									if(((*node_distance)[(links->identifier)-1])==min((*node_distance)[dijkstra_u],links->preference)){
										/*same route type, chooses the one with less hops*/
										if(((*node_hops)[(links->identifier)-1])>((*node_hops)[dijkstra_u]+1))
											(*node_hops)[(links->identifier)-1]=(*node_hops)[dijkstra_u]+1;
									}else{
										/*changed route type so just updates the number of hops*/
										(*node_hops)[(links->identifier)-1]=(*node_hops)[dijkstra_u]+1;
									}					
									(*node_distance)[(links->identifier)-1] = min((*node_distance)[dijkstra_u],links->preference);
							
									//FixUp(heap, heap_place[(links->identifier)-1], (*node_distance), &heap_place);
								}
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
