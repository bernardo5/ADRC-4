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
	
	int * node_statistics = malloc(size*sizeof(int));
	
	init_vector(&node_statistics, size, 0);
	
	int colum;
	int row;
	
	for(colum=0; colum<size; colum++){
		for(row=0; row<size; row++){
			if(row!=colum){
				if(verify_join_nodes(list, colum, row)){
					(node_statistics[0]) ++;
				}else{
					(node_statistics[FordFulkerson(&list, size, &parent, colum, row)]) ++;
					Read_file(ficheiroIn, &list);
				}
			}
		}
	}
	
	for(colum=0; colum<size; colum++){
		printf("%d %d\n", colum, node_statistics[colum]);
	}
	
	
	exit(0);
}
