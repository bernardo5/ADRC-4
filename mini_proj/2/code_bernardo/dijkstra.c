#include "dijkstra.h"

int max(int i, int n){
	if(i>n){
		return i;
	}else{
		return n;
	}
	return -1;
}
/*inserts a node in the dijkstra queue*/
void insert(int identifier, node**list){
	node *n;
	n=(node*)malloc(sizeof(node));
	n->identifier=identifier;
	n->next=(*list);
	n->link=NULL;
	(*list)=n;
	//free(n);
	return;
}

void Initialize_distance_matrix(int**node_identifiers, int**node_distance, node *list, int destiny, node**visited_nodes){
	int i;
	node*aux;
	for(i=0, aux=list; aux!=NULL; aux=aux->next, i=i+1 ){
		(*node_identifiers)[i]=aux->identifier;
		(*node_distance)[i]=-1; /*infinity distance*/
		if((aux->identifier)==destiny){
			(*node_distance)[i]=0;
		}
		insert(aux->identifier, &(*visited_nodes));
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

int empty_queue(node*visited_nodes){
	if(visited_nodes==NULL) return 0;
	return 1;
}

int identifier_smaller_distance(int*node_identifiers, int*node_distance, int count_nodes, node*visited_nodes){
	int i, position=-1;
	int dist=-4;
	node*aux;
	/*loop to see which one has a smaller distance to destiny*/
	for(aux=visited_nodes; aux!=NULL; aux=aux->next){
		/*loop to get the colum of the selected item in the queue*/
		for(i=0; (node_identifiers[i]!=(aux->identifier))&&(i<count_nodes); i++);
		if(node_distance[i]>dist){
			dist=node_distance[i];
			position=i;
		}
	}
	/*after the loop we get the colum of the vector that has the
	 * best candidate for next iteration in dijkstra*/
	return position;
}

void Dijkstra(node*list, int destiny){
	int e;
	int count_nodes=0;
	node*aux;
	adj_node*links;
	int dijkstra_u=0;
	for(aux=list; aux!=NULL; aux=aux->next)count_nodes=count_nodes+1;
	printf("numero de nos:%d\n\n", count_nodes);
	int colum;
	if(count_nodes>0){
		node*visited_nodes=NULL;
		int*node_identifiers=malloc(count_nodes*sizeof(int));
		int*node_distance=malloc(count_nodes*sizeof(int));
		printf("Alocou a matriz\n");
		Initialize_distance_matrix(&node_identifiers, &node_distance, /*&node_visited,*/ list, destiny, &visited_nodes);
		printf("Analizou a matriz das distancias\n");
		
		
	
		for(dijkstra_u=0; dijkstra_u<count_nodes; dijkstra_u++)printf("%d\t", node_identifiers[dijkstra_u]);
		printf("\n\n");
		
		for(dijkstra_u=0; dijkstra_u<count_nodes; dijkstra_u++)printf("%d\t", node_distance[dijkstra_u]);
		printf("\n\n");
		
		int hj=1;
		while(/*empty_queue(visited_nodes)*/ hj){
			hj=0;
			dijkstra_identifier=identifier_smaller_distance(node_identifiers, node_distance, count_nodes, visited_nodes);
			dijkstra_u=node_identifiers[dijkstra_identifier];
			if(node_distance[dijkstra_identifier]=!=-1){
				/*access node identifier adjency list*/				
				for(aux=list;aux->identifier!=dijkstra_u;aux=aux->next);
				/*for each uv*/
					for(links=aux->link;links!=NULL; links=links->next){
						for(colum=0; node_identifiers[colum]!=links->identifier; colum++);
						if(node_distance[colum] < max(node_distance[dijkstra_u],links->preference)){
							node_distance[colum] = max(node_distance[dijkstra_u],links->preference);
						}						
					}
			}
			//***************************************************
				printf("\n");
				for(e=0; e<count_nodes; e++){
					printf("%d\t%d\n", node_identifiers[e], node_distance[e]);
				}
				printf("\n");
				//***************************************************
			//printf("no retirado que deu merda:%d\n", dijkstra_u);
		}
		printf("\n\nfinal\n\n");	
		for(colum=0; colum<count_nodes; colum++){
			printf("%d\t%d\n", node_identifiers[colum], node_distance[colum]/*, node_visited[colum]*/);
		}
	}
	return;
}
