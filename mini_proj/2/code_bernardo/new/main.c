#include "dijkstra.h"

int main(int argc, char**argv){
	char * ficheiroIn;
	node*list=NULL;
	node*aux;
	int count_nodes=0;
	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}
	ficheiroIn = argv[1];
	
	Read_file(ficheiroIn, &list);
	
	/*node*aux;
	adj_node*aux_adj;
	for(aux=list;aux!=NULL;aux=aux->next){
		for(aux_adj=aux->link;aux_adj!=NULL; aux_adj=aux_adj->next){
			 printf("%d %d %d\n", aux->identifier, aux_adj->identifier, aux_adj->preference);
		 }
	}*/
	for(aux=list; aux!=NULL; aux=aux->next)count_nodes=count_nodes+1;
	int*node_identifiers=malloc(count_nodes*sizeof(int));
	int*node_distance=malloc(count_nodes*sizeof(int));
	int*node_hops=malloc(count_nodes*sizeof(int));
	
	Dijkstra(list, 4, count_nodes, &node_identifiers, &node_distance, &node_hops);
	int colum;
	for(colum=0; colum<count_nodes; colum++){
		printf("%d\t%d\t%d\n", (node_identifiers)[colum], (node_distance)[colum], (node_hops)[colum]);
	}
	exit(0);
}
