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
	list[1].minus=NULL;
	BFS(0, list, &parent, size);
	printf("path %d\n", path(parent, 0, 3));
	exit(0);
}
