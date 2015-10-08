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
	
	int option;
	int hop;
	char prefix[128];
	
	while(1){
		
		printf("Choose from the following options:\n1: Add Prefix\n2: Delete Prefix\n3: Print Table\n4: Convert Tree to Two Tree\n5: Address Look Up\n6: Exit\n\n");
		
		bzero(prefix, 128);
		scanf("%d",&option);

		if(option==1){
			printf("\nPlease specify the prefix and next hop to add.\n");
			fscanf(stdin,"%s %d", prefix, &hop);
			AddPrefix(&root, prefix, hop);
			printf("\nAdded the prefix: %s with next hop: %d\n",prefix, hop);
		}
		if(option==2){
			printf("\nPlease specify the prefix to delete.\n");
			fscanf(stdin,"%s", prefix);
			printf("\n%s\t%d\n",prefix, hop);
			DeletePrefix(&root, prefix);
			printf("\nDeleted the prefix: %s\n",prefix);
		}
		if(option==3){
			PrintTable(root);
			printf("\nTable successfully printed\n");	
		}
		if(option==4){
			convert_tree(&root, root->next_hop);
			printf("\nTable successfully converted\n");
		}
		if(option==5){
			printf("\nPlease specify the prefix to scan.\n");
			fscanf(stdin,"%s", prefix);
			int result=AddressLookUp(root, prefix);
			printf("\nNext hop is: %d\n", result);
		}
		if(option==6){
			printf("The program will now exit.\n");
			exit(1);
		}
	}
	exit(0);
}
