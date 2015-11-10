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

void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, dij_node**visited_nodes){
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



int unseen_nodes_list(int * node_visited, int colums){
	int i;
	for(i=0; i<colums;i++){
		if(node_visited[colums]==0) return 1;
	}
	return 0;
}

int empty_queue(dij_node*visited_nodes){
	if(visited_nodes==NULL) return 0;
	return 1;
}

int identifier_smaller_distance(int*node_distance, int*node_hops, int count_nodes, dij_node*visited_nodes){
	int position=-1;
	int dist=-4;
	int hops=50000;
	dij_node*aux;
	/*loop to see which one has a smaller distance to destiny*/
	for(aux=visited_nodes; aux!=NULL; aux=aux->next){
		if(node_distance[(aux->identifier)-1]>=dist){
			if(node_hops[(aux->identifier)-1]<=hops){
				dist=node_distance[(aux->identifier)-1];
				hops=node_hops[(aux->identifier)-1];
				position=(aux->identifier)-1;
			}
		}
	}
	/*after the loop we get the colum of the vector that has the
	 * best candidate for next iteration in dijkstra*/
	return position;
}

void remove_element_from_queue(dij_node**unvisited_nodes, int dijkstra_identifier){
	dij_node*aux=(*unvisited_nodes);
	dij_node*aux_ant;
	/*remove first element case*/
	if((aux->identifier)==dijkstra_identifier){
		(*unvisited_nodes)=aux->next;
		//free(aux);
	}else{/*remove element from end or middle*/
		aux_ant=aux;
		aux=aux->next;
		while(aux->identifier!=dijkstra_identifier){
			aux=aux->next;
			aux_ant=aux_ant->next;
		}
		aux_ant->next=aux->next;
	}
	free(aux);
	
	return;
}

int verify_node_unseen(int node_identifier, dij_node*unvisited_nodes){
	dij_node*aux;
	for(aux=unvisited_nodes; aux!=NULL; aux=aux->next){
		if((aux->identifier)==node_identifier)return 1;
	}
	return 0;
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
	if(count_nodes>0){
		dij_node*unvisited_nodes=NULL;
		Initialize_distance_matrix(count_nodes, &(*node_distance), &(*node_hops), list, destiny, &unvisited_nodes);
		while(empty_queue(unvisited_nodes)){
			dijkstra_u=identifier_smaller_distance((*node_distance), (*node_hops), count_nodes, unvisited_nodes);
			dijkstra_identifier=dijkstra_u + 1;
			remove_element_from_queue(&unvisited_nodes, dijkstra_identifier);
			if((*node_distance)[dijkstra_u]!=-1){
				/*for each uv*/
					for(links=(list[dijkstra_u]).link;links!=NULL; links=links->next){
						if(verify_node_unseen(links->identifier, unvisited_nodes)){
							if(((*node_distance)[(links->identifier)-1] < min((*node_distance)[dijkstra_u],links->preference))&&
								((links->preference)<=(*node_distance)[dijkstra_u])){
								(*node_distance)[(links->identifier)-1] = min((*node_distance)[dijkstra_u],links->preference);
								(*node_hops)[(links->identifier)-1]=(*node_hops)[dijkstra_u]+1;
							}		
						}			
					}
			}
		}
		invert_weights(&(*node_distance), count_nodes);	
	}
	return;
}
