#include "dijkstra.h"

void Initialize_distance_matrix(int*** distance, node *list, int destiny){
	int i;
	node*aux;
	for(i=0, aux=list; aux!=NULL; aux=aux->next, i=i+1 ){
		printf("inicializacao do no %d\n", i);
		*distance[0][i]=aux->identifier;
		printf("identificador: %d\n", *distance[0][i]); 
		printf("sdnv\n");
		*distance[1][i]=-1; /*infinity distance*/
		printf("nsdnvj\n");
		*distance[2][i]=0; /*node not seen*/
		printf("nsdnvcadcadvavj\n");
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
	int **distance = (int **)malloc(3 * sizeof(int *)); 
    int row;

	
    // for each row allocate Cols ints
    for (row = 0; row < 3; row++) {
        distance[row] = (int *)malloc(count_nodes * sizeof(int));
    }
	printf("Alocou a matriz\n");
	Initialize_distance_matrix(&distance, list, destiny);
	printf("Analizou a matriz das distancias\n");
	int count_nodes_cycle=count_nodes;
	printf("numero de nos: %d\n", count_nodes);
	while(count_nodes_cycle!=0){
		dijkstra_distance=-5;
		
		/*  ******************************************************** */
		/* select a node u of Q for which d[u] is smallest */
		for(row=0; row<count_nodes; row++){
			if((dijkstra_distance<distance[1][row])&&
				(distance[2][row]==0)){
				dijkstra_distance=distance[1][row];
				dijkstra_u=distance[0][row];
			}
		}
		/* ********************************************************* */
		
		/*node was visited now*/
		for(row=0; dijkstra_u!=distance[0][row]; row++) distance[2][row]=1;
		/* ********************************************************* */
		
		/* for each uv */
		
		for(aux=list;aux->identifier!=dijkstra_u;aux=aux->next);		
		
		//new_node=aux->link->identifier;
		
		
		
		//for(row=0; distance[0][row]!=new_node; row++);
		//distance[2][row]=1; /*node already visited*/ 
		//dist=distance[1][row];
		//for(aux=list;aux->identifier!=new_node;aux=aux->next);
		for(links=aux->link;links!=NULL; links=links->next){
			for(row=0; distance[0][row]!=links->identifier; row++);
			if(distance[1][row] < max(dijkstra_u,links->preference)) 
					distance[1][row] = max(dijkstra_u,links->preference);
		}
		count_nodes_cycle--;
	}
	
	return;
}
