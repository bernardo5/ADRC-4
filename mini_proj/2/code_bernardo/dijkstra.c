#include "dijkstra.h"

void Initialize_distance_matrix(int**node_identifiers, int**node_distance, int**node_visited, node *list, int destiny){
	int i;
	node*aux;
	for(i=0, aux=list; aux!=NULL; aux=aux->next, i=i+1 ){
		printf("inicializacao do no %d\n", i);
		(*node_identifiers)[i]=aux->identifier;
		printf("identificador: %d\n", (*node_identifiers)[i]); 
		(*node_distance)[i]=-1; /*infinity distance*/
		(*node_visited)[i]=0; /*node not seen*/
		if((aux->identifier)==destiny){
			(*node_distance)[i]=0;
			(*node_visited)[i]=1;
		}
	}
	return;
}

int max(int i, int n){
	if(i>n){
		return i;
	}else{
		return n;
	}
	return -1;
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
	int dijkstra_distance;
	for(aux=list; aux!=NULL; aux=aux->next)count_nodes=count_nodes+1;
	int colum;
	int*node_identifiers=malloc(count_nodes*sizeof(int));
	int*node_distance=malloc(count_nodes*sizeof(int));
	int*node_visited=malloc(count_nodes*sizeof(int));
	
	printf("Alocou a matriz\n");
	Initialize_distance_matrix(&node_identifiers, &node_distance, &node_visited, list, destiny);
	printf("Analizou a matriz das distancias\n");
	int count_nodes_cycle=count_nodes;
	printf("numero de nos: %d\n", count_nodes);
	while(/*unseen_nodes_list(node_visited, count_nodes)*/count_nodes_cycle!=0){
		dijkstra_distance=-5;
		printf("count nodes:%d\n", count_nodes_cycle);
		
		/*  ******************************************************** */
		/* select a node u of Q for which d[u] is smallest */
		for(colum=0; colum<count_nodes; colum++){
			if(node_visited[colum]==0 && node_visited[colum+1]==0){
				dijkstra_distance=max(node_distance[colum],node_distance[colum+1]);
			}else if(node_visited[colum]==0){
				dijkstra_distance=node_distance[colum];
			}
		}
		dijkstra_distance=node_distance[colum];
		dijkstra_u=node_identifiers[colum];
		/* ********************************************************* */
		
		/*node was visited now*/
		for(colum=0; dijkstra_u!=node_identifiers[colum]; colum++);
		node_visited[colum]=1;
		/* ********************************************************* */
		
		/* for each uv */
		
		for(aux=list;aux->identifier!=dijkstra_u;aux=aux->next);		
		
		for(links=aux->link;links!=NULL; links=links->next){
			for(colum=0; node_identifiers[colum]!=links->identifier; colum++);
			if(node_distance[colum] < max(dijkstra_distance,links->preference)) 
					node_distance[colum] = max(dijkstra_distance,links->preference);
		}
		count_nodes_cycle--;
	}
	
	for(colum=0; colum<count_nodes; colum++){
		printf("%d\t%d\t%d\n", node_identifiers[colum], node_distance[colum], node_visited[colum]);
	}
	
	return;
}
