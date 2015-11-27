#include "file.h"

void create_link_entry(node**n, int initial_node, int final_node){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		
		temp->identifier=final_node;
		
		/*insertion in the beginning*/
		temp->next=((*n)[initial_node]).link;
		((*n)[initial_node]).link=temp; 

		return;
}

int get_table_line(int * initial_node, int * final_node, FILE*fp){
	if(fscanf(fp, "%d %d", initial_node, final_node)!=3){
		return -1;
	}
	return 0;
}

void list_adj(node**list, int initial_node, int final_node){
	create_link_entry(&(*list), initial_node, final_node);	
	return;
}

void Read_file(char * ficheiroIn, node**list){
	
	FILE*fp;
	int initial_node;
	int final_node;

	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    (*list)=malloc((100)*sizeof(node));
    if((*list)==NULL)printf("ERROR IN MALLOC\n");
	
	int i=0;
	for(i=0; i<100; i++){
		((*list)[i]).link=NULL;
	}
    
    while(get_table_line(&initial_node, &final_node, fp)==0){
		list_adj(&(*list), initial_node, final_node);
	}
	
	fclose(fp);
	
	node * aux_node;
	adj_node * aux_adj_node;
	
	for(aux_node = list; aux_node != NULL; aux_node = aux_node.next){
		for(aux_adj_node = aux_node.link; aux_adj_node != NULL; aux_adj_node = aux_adj_node.next){
			printf("%d -> %d\t", aux_node->identifier, aux_adj_node.identifier);
		}
		printf("\n");
	}	
	
	return;
}
