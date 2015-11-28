#include "ford-folkerson.h"

int verify_join_nodes(node*list, int initial_node, int final_node){
	int join=0;
	adj_node*aux_adj_node;
	for(aux_adj_node=((list)[initial_node]).plus; aux_adj_node!=NULL; aux_adj_node=aux_adj_node->next){
		printf("identifier: %d\n", aux_adj_node->identifier);
		if(aux_adj_node->identifier==final_node)join=1;
	}
	
	for(aux_adj_node=((list)[final_node]).plus; aux_adj_node!=NULL; aux_adj_node=aux_adj_node->next){
		if(aux_adj_node->identifier==initial_node)join=1;
	}
	
	return join;
}


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
	
	if(verify_join_nodes(list, initial_node, final_node)){
		printf("nodes are connected, cannot take a node between them to separate them\n");
	}else{
		FordFulkerson(&list, size, &parent, initial_node, final_node);
	}
	
	exit(0);
}
