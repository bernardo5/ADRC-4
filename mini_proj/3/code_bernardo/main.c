#include "ford-folkerson.h"

int main(int argc, char**argv){
	char * ficheiroIn;
	node * list;
	int size;

	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}

	ficheiroIn = argv[1];

	size=Read_file(ficheiroIn, &list);
	printf("size= %d\n", size);
	int*parent=malloc(size*sizeof(int));
	//list[1].minus=NULL;
	FordFulkerson(&list, size, &parent, 0, 3);
	exit(0);
}
