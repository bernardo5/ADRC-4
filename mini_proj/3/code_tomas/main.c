#include "ford_fulkerson.h"

int main(int argc, char**argv){
	char * ficheiroIn;
	node * list;

	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}

	ficheiroIn = argv[1];

	
	int size = Read_file(ficheiroIn, &list);
	printf("\nSIZE : %d\n", size);
	
	int * parent = malloc(size*sizeof(int));
	BFS(list, 0, &parent, size);
	printf("path = %d\n", path(0, 3, parent));
	
	exit(0);
}
