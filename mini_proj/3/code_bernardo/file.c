#include "file.h"

void create_link_entry_same(node**n, int initial_node){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		
		temp->identifier=initial_node;
		
		/*insertion in the beginning*/
		temp->next=NULL;
		temp->capacity=1;
		((*n)[initial_node]).minus=temp; 

		return;
}

void create_link_entry(node**n, int initial_node, int final_node){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		
		temp->identifier=final_node;
		
		/*insertion in the beginning*/
		temp->next=((*n)[initial_node]).plus;
		temp->capacity=2;
		if(initial_node==final_node) temp->capacity=1;
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
	int size=0;
	
	/*****************************************************************/
	/*getting number of nodes*/
	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    
     while(get_table_line(&initial_node, &final_node, fp)==0){
		if(size<initial_node) size=initial_node;
	}
    
    fclose(fp);
    size=size+1;
	/*********************************************************************/
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
		//printf("intial_node: %d, final_node:%d\n", initial_node, final_node);
	}
	
	fclose(fp);
	
	adj_node * aux_adj_node;
	
	for(i=0; i<size; i++){
		printf("\n node %d \n", i);
		printf("\t minus: connected to %d with capacity %d\n", (((*list)[i]).minus)->identifier, (((*list)[i]).minus)->capacity);
		for(aux_adj_node = ((*list)[i]).plus; aux_adj_node != NULL; aux_adj_node = aux_adj_node->next){
			printf("\t plus: connected to %d with capacity %d\n", aux_adj_node->identifier, aux_adj_node->capacity);
		}
		printf("\n");
	}
	
	return size;
}
