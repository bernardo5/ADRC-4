#include "statistics.h"


int main(int argc, char**argv){
	char * ficheiroIn;
	node*list=NULL;
	node*aux;
	float stat_customer, stat_peer, stat_provider, stat_hops;
	int count_nodes=0;
	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}
	ficheiroIn = argv[1];
	
	Read_file(ficheiroIn, &list);
	printf("Criou lista\n");
	adj_node*aux_adj;
	int vec;
	for(vec=0;vec<positions(ficheiroIn);vec++){
		for(aux_adj=list[vec].link;aux_adj!=NULL; aux_adj=aux_adj->next){
			 printf("%d %d %d\n", list[vec].identifier, aux_adj->identifier, aux_adj->preference);
		 }
	}
	/*for(aux=list; aux!=NULL; aux=aux->next)count_nodes=count_nodes+1;
	int*node_identifiers=malloc(count_nodes*sizeof(int));
	int*node_distance=malloc(count_nodes*sizeof(int));
	int*node_hops=malloc(count_nodes*sizeof(int));
	Dijkstra(list, 1, count_nodes, &node_identifiers, &node_distance, &node_hops);
	int colum;
	for(colum=0; colum<count_nodes; colum++){
		printf("%d\t%d\t%d\n", (node_identifiers)[colum], (node_distance)[colum], (node_hops)[colum]);
	}
	
	paths_statistics(&stat_customer, &stat_peer, &stat_provider, count_nodes, node_distance);
	
	printf("customer: %f\nstat_peer:%f\nstat_provider:%f\n\n", stat_customer, stat_peer, stat_provider);
	
	number_hops_statistics(count_nodes, node_hops, &stat_hops);
	printf("medium number of hops: %f\n", stat_hops);*/
	
	
	exit(0);
}
