#include "two_tree.h"

int main(int argc, char *argv[]){
	
	if(argc!=2){
		printf("Specify the file name\n");
		exit(-1);
	}
	
	char*table_txt=argv[1];
	
	node*root=Init_tree();
	
	if(root==NULL)printf("Table successfully initialized\n");
	
	ReadTable(&root, table_txt);
	
	/*AddPrefix(&root, "001", 10);*/
	  
	/*DeletePrefix(&root, "000");*/
	
	/*DeletePrefix(&root, "*");*/
	
	/*DeletePrefix(&root, "11");*/
	
	PrintTable(root);
	
	convert_tree(&root, root->next_hop);
	
	PrintTable(root);
	
	exit(0);
}
