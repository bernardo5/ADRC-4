#include "dijkstra.h"


void free_adjacency_list(node**list, int size){
	int i;
	adj_node*links, *remove;
	for(i=0;i<size;i++){
		links=(*list)[i].link;
		while(links!=NULL){
			remove=links;
			links=links->next;
			free(remove);
		}
	}
	return;
}

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
	/*get graph into adjacency list*/
	Read_file(ficheiroIn, &list, &size);
	int*node_distance=malloc(size*sizeof(int)); /*used to know what type of route a node uses to reach destiny*/
	if(node_distance==NULL)exit(-1);
	int*node_hops=malloc(size*sizeof(int)); /*used to know how many hops a node take to reach the destiny*/
	if(node_hops==NULL)exit(-1);
	int*stat_hops=malloc(50*sizeof(int)); /*used to calc statistics*/
	if(stat_hops==NULL)exit(-1);
	int be;
	
	for(be=0; be<50;be++){
		stat_hops[be]=0;
	}
	
	float ones=0, twos=0, threes=0, unusable=0;
	int colum=0;
	for(colum=0; colum<size; colum++){
		if((list[colum].link)!=NULL){ /*node exists*/
			//printf("\nfinished dijkstra para %d\n", colum+1);
			Dijkstra(list, colum+1, size, &node_distance, &node_hops);
			/*for(be=0; be<size; be++){
				if((list[be].link)!=NULL){
					printf("%d\t%d\t%d\n", be+1, (node_distance)[be], (node_hops)[be]);
				}
			}*/
			paths_count(list, size, node_distance, &ones, &twos, &threes, &unusable);
			hops_count(&stat_hops, node_hops, size);
		}
	}
	/*sem heap*/
	paths_statistics(&stat_customer, &stat_peer, &stat_provider, count_number_nodes(list, size), ones, twos, threes, unusable);
	
	printf("customer: %f\nstat_peer:%f\nstat_provider:%f\n\n", stat_customer, stat_peer, stat_provider);
	
	number_hops_statistics(stat_hops);
	
	free(node_distance);
	free(node_hops);
	free(stat_hops);
	free_adjacency_list(&list, size);
	free(list);
	
	exit(0);
}
