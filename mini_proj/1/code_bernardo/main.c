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
	int control=0;
	char number[2];
	while(1){

		printf("Choose from the following options:\n1: Add Prefix\n2: Delete Prefix\n3: Print Table\n4: Convert Tree to Two Tree\n5: Address Look Up\n6: Exit\n\n");

		bzero(prefix, 128);
		fgets(number, 2, stdin);
		
		if(sscanf(number, "%d", &option)==1){
			if(option==1){
				printf("\nPlease specify the prefix and next hop to add.\n");
				scanf("%s %d", prefix, &hop);
				control=0;
				AddPrefix(&root, prefix, hop);
			}
			else if(option==2){
				printf("\nPlease specify the prefix to delete.\n");
				fscanf(stdin,"%s", prefix);
				if(DeletePrefix(&root, prefix)!=-1){
					printf("\nPrefix successfully deleted.\n\n");			
					control=0;
				}
			}
			else if(option==3){
				PrintTable(root);
				printf("\nTable successfully printed\n");
			}
			else if(option==4){
				control=1;
				TwoTree(&root, root->next_hop);
				printf("\nTable successfully converted\n");
			}
			else if(option==5){
				if(control==0){
					printf("\nPlease convert the tree to a two tree first.\n\n");
				}else{
					printf("\nPlease specify the prefix to scan.\n");
					fscanf(stdin,"%s", prefix);
					printf("\nNext hop is: %d\n", AddressLookUp(root, prefix));
				}
			}
			else if(option==6){
				printf("The program will now exit.\n");
				exit(1);
			}
		}
	}
	exit(0);
}
