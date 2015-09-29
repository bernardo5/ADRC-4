#include "tree.h"

int main(int argc, char *argv[]){
	
	if(argc!=2){
		printf("Specify the file name\n");
		exit(-1);
	}
	
	char *table_txt=argv[1];
	
	node*root=Init_tree();
	
	if(root==NULL)printf("Table successfully initialized\n");
	
	
	
	ReadTable(&root, table_txt);
	
	exit(0);
}
