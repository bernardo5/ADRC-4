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
	
	AddPrefix(&root, "001", 10);
	printf("001 next hop is: %d\n", root->zero->zero->one->next_hop);
	printf("00 next hop is: %d\n", root->zero->zero->next_hop);
	printf("0 next hop is: %d\n", root->zero->next_hop);
	
	DeletePrefix(&root, "000");
	
	DeletePrefix(&root, "*");
	
	DeletePrefix(&root, "00");
	
	PrintTable(root);
	
	exit(0);
}
