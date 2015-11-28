#include "ford_fulkerson.h"


int main(int argc, char**argv){
	char * ficheiroIn;
	node * list;
	int initial_node, final_node;

	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}
	
	printf("PLEAS CHOOSE A SOURCE AND DESTINATION.\n");

	if(scanf("%d %d", &initial_node, &final_node)!=2){
		printf("ERROR: SPECIFY A VALID SOURCE AND DESTINATION\n");
		exit(0);
	}

	ficheiroIn = argv[1];
	
	int size = Read_file(ficheiroIn, &list);

	contiguous(list, initial_node, final_node);

	int * parent = malloc(size*sizeof(int));
	
	int count_nodes = ford_fulkerson(&list, size, &parent, initial_node, final_node);
	
	printf("\nNODES NEEDED TO SPLIT NODE %d FROM NODE %d IS %d\n", initial_node, final_node, count_nodes);
	
	exit(0);
}
