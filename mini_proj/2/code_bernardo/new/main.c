#include "statistics.h"


int main(int argc, char**argv){
	char * ficheiroIn;
	node*list;
	int size;
	float stat_customer, stat_peer, stat_provider;
	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}
	ficheiroIn = argv[1];
	Read_file(ficheiroIn, &list, &size);
	/*adj_node*aux_adj;
	int vec;
	for(vec=0;vec<positions(ficheiroIn);vec++){
		for(aux_adj=list[vec].link;aux_adj!=NULL; aux_adj=aux_adj->next){
			 printf("%d %d %d\n", vec+1, aux_adj->identifier, aux_adj->preference);
		 }
	}*/
	int*node_distance=malloc(size*sizeof(int));
	int*node_hops=malloc(size*sizeof(int));
	int*stat_hops=malloc(50*sizeof(int)); /*used to calc statistics*/
	int be;
	for(be=0; be<50;be++){
		stat_hops[be]=0;
	}
	
	float ones=0, twos=0, threes=0;
	int colum;
	for(colum=0; colum<size; colum++){
		if((list[colum].link)!=NULL){ /*node exists*/
			Dijkstra(list, colum+1, size, &node_distance, &node_hops);
			/*for(be=0; be<size; be++){
				if((list[be].link)!=NULL){
					printf("%d\t%d\t%d\n", be+1, (node_distance)[be], (node_hops)[be]);
				}
			}*/
			paths_count(size, node_distance, &ones, &twos, &threes);
			hops_count(&stat_hops, node_hops, size);
			printf("finished one dijkstra\n");
		}
	}
	/*sem heap*/
	paths_statistics(&stat_customer, &stat_peer, &stat_provider, count_number_nodes(list, size), ones, twos, threes);
	
	printf("customer: %f\nstat_peer:%f\nstat_provider:%f\n\n", stat_customer, stat_peer, stat_provider);
	
	number_hops_statistics(stat_hops);
	
	
	exit(0);
}
