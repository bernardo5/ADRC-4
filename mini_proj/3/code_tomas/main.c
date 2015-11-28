#include "ford_fulkerson.h"

int main(int argc, char**argv){
	char * ficheiroIn;
	node * list;
	int initial_node, final_node;

	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}
	
	printf("Please choose a source and a destination.\n");

	if(scanf("%d %d", &initial_node, &final_node)!=2){
		printf("ERROR: Specify a valid source and destination\n");
		exit(0);
	}

	ficheiroIn = argv[1];
	
	int size = Read_file(ficheiroIn, &list);
	
	/****************************Verifcação de contiguidade**********************************/
	
	node aux_node;
	adj_node * aux_adj_node;
	
	aux_node = list[initial_node];
	for(aux_adj_node = aux_node.plus; aux_adj_node != NULL && aux_adj_node->identifier!=final_node;
																aux_adj_node = aux_adj_node->next);
	if(aux_adj_node!=NULL){
		printf("THERE IS NO WAY OF SEPARATING NODE %d FROM NODE %d BECAUSE THEY ARE CONTIGUOUS\n", initial_node, final_node);
		exit(0);
	}
	
	/****************************************************************************************/
	
	int * parent = malloc(size*sizeof(int));
	
	int count_nodes = ford_fulkerson(&list, size, &parent, initial_node, final_node);
	
	printf("\nNODES NEEDED TO SPLIT NODE %d FROM NODE %d IS %d\n", initial_node, final_node, count_nodes);
	
	exit(0);
}
