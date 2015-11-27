#include "file.h"
#include "ford-folkerson.h"

int main(int argc, char**argv){
	char * ficheiroIn;
	node * list;

	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}

	ficheiroIn = argv[1];

	Read_file(ficheiroIn, &list);
	
	
	
	exit(0);
}
