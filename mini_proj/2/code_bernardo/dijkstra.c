#include "dijkstra.h"

void Initialize_distance_matrix(int**node_identifiers, int**node_distance, int**node_visited, node *list, int destiny){
	int i;
	node*aux;
	for(i=0, aux=list; aux!=NULL; aux=aux->next, i=i+1 ){
		printf("inicializacao do no %d\n", i);
		(*node_identifiers)[i]=aux->identifier;
		printf("identificador: %d\n", (*node_identifiers)[i]); 
		printf("sdnv\n");
		(*node_distance)[i]=-1; /*infinity distance*/
		printf("nsdnvj\n");
		(*node_visited)[i]=0; /*node not seen*/
		printf("nsdnvcadcadvavj\n");
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

/*void unseen_nodes_list(){
	
	return;
}*/

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
	while(count_nodes_cycle!=0){
		dijkstra_distance=-5;
		
		/*  ******************************************************** */
		/* select a node u of Q for which d[u] is smallest */
		for(colum=0; colum<count_nodes; colum++){
			if((dijkstra_distance<node_distance[colum])&&
				(node_visited[colum]==0)){
				dijkstra_distance=node_distance[colum];
				dijkstra_u=node_identifiers[colum];
			}
		}
		/* ********************************************************* */
		
		/*node was visited now*/
		for(colum=0; dijkstra_u!=node_identifiers[colum]; colum++) node_visited[colum]=1;
		/* ********************************************************* */
		
		/* for each uv */
		
		for(aux=list;aux->identifier!=dijkstra_u;aux=aux->next);		
		
		//new_node=aux->link->identifier;
		
		
		
		//for(row=0; distance[0][row]!=new_node; row++);
		//distance[2][row]=1; /*node already visited*/ 
		//dist=distance[1][row];
		//for(aux=list;aux->identifier!=new_node;aux=aux->next);
		for(links=aux->link;links!=NULL; links=links->next){
			for(colum=0; node_identifiers[colum]!=links->identifier; colum++);
			if(node_distance[colum] < max(dijkstra_u,links->preference)) 
					node_distance[colum] = max(dijkstra_u,links->preference);
		}
		count_nodes_cycle--;
	}
	
	
	
	return;
}
