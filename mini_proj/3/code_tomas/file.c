#include "file.h"

void create_link_entry_same(node**n, int initial_node){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		
		temp->identifier = initial_node;
		temp->capacity=1;
		
		/*insertion in the beginning*/
		temp->next = NULL;
		((*n)[initial_node]).minus = temp; 

		return;
}

void create_link_entry(node**n, int initial_node, int final_node){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		
		temp->identifier=final_node;
		temp->capacity=2;
		
		if(initial_node==final_node) temp->capacity=1;
		
		/*insertion in the beginning*/
		temp->next=((*n)[initial_node]).plus;
		((*n)[initial_node]).plus=temp; 

		return;
}

int get_table_line(int * initial_node, int * final_node, FILE*fp){
	if(fscanf(fp, "%d %d", initial_node, final_node)!=2){
		return -1;
	}
	return 0;
}

void list_adj(node**list, int initial_node, int final_node){
	create_link_entry(&(*list), initial_node, final_node);	
	return;
}

int Read_file(char * ficheiroIn, node**list){
	
	FILE*fp;
	int initial_node;
	int final_node;
	int size = 0;
	
	
	/*---------------------------------------*/
	
	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    while(get_table_line(&initial_node, &final_node, fp)==0){
		if(size < initial_node) size = initial_node;
	}
	
	fclose(fp);
	
	/*---------------------------------------*/
	
	size = size+1;
	
	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    (*list)=malloc((size)*sizeof(node));
    if((*list)==NULL)printf("ERROR IN MALLOC\n");
	
	int i=0;
	for(i=0; i<size; i++){
		create_link_entry_same(&(*list), i);
		((*list)[i]).plus=NULL;
	}
    
    while(get_table_line(&initial_node, &final_node, fp)==0){
		list_adj(&(*list), initial_node, final_node);
	}
	
	fclose(fp);
	
	/*node aux_node;
	adj_node * aux_adj_node;
	
	//PRINT LISTA ADJACENCIAS
	for(i=0; i < size; i++){
		aux_node = (*list)[i];
		printf("\nnode %d\n", i);
		printf("\tminus adjacencia: %d capacity: %d\n", aux_node.minus->identifier, aux_node.minus->capacity);
		for(aux_adj_node = aux_node.plus; aux_adj_node != NULL; aux_adj_node = aux_adj_node->next){
			printf("\tplus adjacencia: %d capacity: %d\t\n", aux_adj_node->identifier, aux_adj_node->capacity);
		}
	}*/
	
	return size;
}

void contiguous(node * list, int initial_node, int final_node){
	
	node aux_node;
	adj_node * aux_adj_node;
	
	/****************************Verifcação de contiguidade para o initial node**********************************/
	
	aux_node = list[initial_node];
	for(aux_adj_node = aux_node.plus; aux_adj_node!=NULL && aux_adj_node->identifier!=final_node;
																aux_adj_node = aux_adj_node->next);
	if(aux_adj_node!=NULL){
		printf("THERE IS NO WAY OF SEPARATING NODE %d FROM NODE %d BECAUSE THEY ARE CONTIGUOUS\n", initial_node, final_node);
		exit(0);
	}
	
	/****************************Verifcação de contiguidade para o final node**********************************/
	
	aux_node = list[final_node];
	for(aux_adj_node = aux_node.plus; aux_adj_node!=NULL && aux_adj_node->identifier!=initial_node;
																aux_adj_node = aux_adj_node->next);
	if(aux_adj_node!=NULL){
		printf("THERE IS NO WAY OF SEPARATING NODE %d FROM NODE %d BECAUSE THEY ARE CONTIGUOUS\n", initial_node, final_node);
		exit(0);
	}
}
