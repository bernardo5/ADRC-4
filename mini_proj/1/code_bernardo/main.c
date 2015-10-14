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
	
	int next_hop=-1; /*variable used to see if AdressLookUp is relevant*/
	int option; /*used to know which function the user wants the program to perform*/
	int hop;	/*used to get next hop for addPrefix function*/
	char prefix[128]; /*used to get from keyboard the prefix the user states*/
	char *aux_prefix=malloc(2*sizeof(char)); /*used in function print table to know the nodes prefixes*/
	int look_up_control=0; /*used to know if Adress Look Up can be called with no chance for errors*/
	char number[2]; /*string used to get the variable option stated before*/
	while(1){
		aux_prefix[0] = '\0';/*inicialization of empty string*/
		
		/*printing options*/
		printf("Choose from the following options:\n");
		printf("1: Add Prefix\n2: Delete Prefix\n3: Print Table\n");
		printf("4: Convert Tree to Two Tree\n5: Address Look Up\n");
		printf("6: Exit\n\n");
		
		bzero(prefix, 128);
		fgets(number, 2, stdin); /*getting option chosen by user*/
		
		if(sscanf(number, "%d", &option)==1){/*verifying if user typed a number*/
			if(option==1){/*AddPrefix*/
				printf("\nPlease specify the prefix and next hop to add.\n");
				scanf("%s %d", prefix, &hop); /*getting prefix to add and next hop*/
				look_up_control=0; /*cant call Address Look Up without converting tree*/
				AddPrefix(&root, prefix, hop);
			}
			else if(option==2){ /*Delete prefix*/
				printf("\nPlease specify the prefix to delete.\n");
				fscanf(stdin,"%s", prefix); /*getting prefix to delete*/
				if(DeletePrefix(&root, prefix)!=-1){
					printf("\nPrefix successfully deleted.\n\n");			
					look_up_control=0; /*cant call Address Look Up without converting tree*/
				}
			}
			else if(option==3){ /*Print table*/
				PrintTable(root, aux_prefix, look_up_control);
				printf("\nTable successfully printed\n");
			}
			else if(option==4){ /*tree conversion*/
				look_up_control=1; /*from now on its possible to look for a next hop*/
				TwoTree(&root, root->next_hop);
				printf("\nTable successfully converted\n");
			}
			else if(option==5){ /*look for next hop of a prefix*/
				if(look_up_control==0){
					printf("\nPlease convert the tree to a two tree first.\n\n");
				}else{
					printf("\nPlease specify the prefix to scan.\n");
					fscanf(stdin,"%s", prefix);
					next_hop=AddressLookUp(root, prefix);
					if(next_hop==-1){ /*number entered is too short*/
						printf("Please specify a valid adress\n\n");
					}else{ /*successfully found a hop*/
						printf("\nNext hop is: %d\n", next_hop);
						next_hop=-1;
					}
				}
			}
			else if(option==6){/*exit option*/
				printf("The program will now exit.\n");
				/*free of everything*/
				free(aux_prefix);
				PosFixed_delete_tree(&root);
				exit(1);
			}
		}
	}
	exit(0);
}
