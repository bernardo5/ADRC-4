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
	PrintTable(root);
	printf("\n\n");
	AddPrefix(&root, "101", 10);
	/*printf("001 next hop is: %d\n", root->zero->zero->one->next_hop);
	printf("00 next hop is: %d\n", root->zero->zero->next_hop);
	printf("0 next hop is: %d\n", root->zero->next_hop);
	*/
	//DeletePrefix(&root, "010");

	//DeletePrefix(&root, "*");

	//DeletePrefix(&root, "10");



	PrintTable(root);

	/*TwoTree(&root, root->next_hop);
	printf("\n\n");
	PrintTable(root);
	printf("\n\n");

	printf("next_hop:\t%d\n",AddressLookUp(root, "1110101010101"));

	printf("next_hop:\t%d\n",AddressLookUp(root, "1110101010101f"));*/
	PosFixed_delete_tree(&root);
	exit(0);
}
