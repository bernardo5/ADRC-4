#include "two_tree.h"

int main(int argc, char *argv[]){
	
	if(argc<2){
		printf("Specify the file name\n");
		exit(-1);
	}
	
	char*table_txt=argv[1];
	
	node*root=Init_tree();
	
	if(root==NULL)printf("Table successfully initialized\n");
	
	ReadTable(&root, table_txt);
	
	/*printf("Choose from the following options:\n1: Add Prefix\n2: Delete Prefix\n3: Print Table\n4: Convert Tree to Two Tree\n\n");
	
	int option;
	int hop;
	char*prefix=NULL;
	fscanf(stdin,"%d",&option);
	
	if(option==1){
		printf("\nPlease specify the prefix.\n");
		fscanf(stdin,"%s",prefix);
		printf("\nPlease specify the next hop.\n");
		fscanf(stdin,"%d",&hop);
		printf("%s\t%d\n", prefix, hop);
	}
	if(option==2){printf("2\n");}
	if(option==3){printf("3\n");}
	if(option==4){printf("4\n");}*/
		
	AddPrefix(&root, "001", 10);
	  
	DeletePrefix(&root, "001");
	
	PrintTable(root);
	
	convert_tree(&root, root->next_hop);
	
	printf("%d\n", AddressLookUp(root, "00110"));
	
	exit(0);
}
