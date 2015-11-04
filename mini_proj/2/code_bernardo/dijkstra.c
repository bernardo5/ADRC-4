#include "dijkstra.h"

void Initialize_distance_matrix(int*** distance, node *list, int destiny){
	int i;
	node*aux;
	for(i=0, aux=list; aux!=NULL; aux=aux->next, i=i+1 ){
		*distance[0][i]=aux->identifier; 
		*distance[1][i]=-1; /*infinity distance*/
		*distance[2][i]=0; /*node not seen*/
		if(aux->identifier==destiny){
			*distance[1][i]=0;
			*distance[2][i]=1;
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

void Dijkstra(node*list, int destiny){
	
	int count_nodes=0;
	node*aux;
	adj_node*links;
	for(aux=list; aux!=NULL; aux=aux->next)count_nodes=1+count_nodes;
	
	int new_node;
	int dist;
	int **distance = (int **)malloc(3 * sizeof(int *)); 
    int row;

    // for each row allocate Cols ints
    for (row = 0; row < count_nodes; row++) {
        distance[row] = (int *)malloc(count_nodes * sizeof(int));
    }
	
	Initialize_distance_matrix(&distance, list, destiny);
	
	while(count_nodes!=0){
	
		for(aux=list;aux->identifier!=destiny;aux=aux->next);		
		new_node=aux->link->identifier;
		for(row=0; distance[0][row]!=new_node; row++);
		distance[2][row]=1; /*node already visited*/ 
		dist=distance[1][row];
		for(aux=list;aux->identifier!=new_node;aux=aux->next);
		for(links=aux->link;links!=NULL; links=links->next){
			for(row=0; distance[0][row]!=links->identifier; row++);
			if(distance[1][row] < max(dist,links->preference)) 
					distance[1][row] = max(dist,links->preference);
		}
		count_nodes--;
	}
	
	return;
}
