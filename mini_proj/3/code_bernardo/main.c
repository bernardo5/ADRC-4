#include "ford-folkerson.h"

int main(int argc, char**argv){
	char * ficheiroIn;
	node * list;
	int initial_node, final_node;
	int size;
    char numbers[100];
	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}

	ficheiroIn = argv[1];

	size=Read_file(ficheiroIn, &list);
	printf("size= %d\n", size);
	int*parent=malloc(size*sizeof(int));
	//list[1].minus=NULL;
	printf("Please insert <initial_node> <final_node>\n");
	if(fgets(numbers,100,stdin)==NULL){
		printf("error getting nodes\n");
		exit(-1);
	} 
	if(sscanf(numbers, "%d %d", &initial_node, &final_node)!=2){
		printf("error\n");
		exit(-1);
	}
	
	FordFulkerson(&list, size, &parent, initial_node, final_node);
	exit(0);
}
