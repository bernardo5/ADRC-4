#include "lista_adjacencias.h"

int positions(char * ficheiroIn){
	int size=0;
	int initial_node, final_node, preference;
	FILE*fp;
	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    while(get_table_line(&initial_node, &final_node, &preference, fp)==0){
		if(initial_node>size)size=initial_node;
	}
    
	fclose(fp);
	return size;
}


int get_table_line(int * initial_node, int *final_node , int*preference, FILE*fp){
	if(fscanf(fp, "%d %d %d", initial_node, final_node, preference)!=3){
		return -1;
	}
	return 0;
}

void create_link_entry(node**n, int initial_node, int final_node, int preference){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		temp->identifier=final_node;
		temp->preference=preference;
		
		/*insertion in the beginning*/
		temp->next=((*n)[initial_node-1]).link;
		((*n)[initial_node-1]).link=temp; 

		return;
}

void list_adj(node**list, int initial_node, int final_node, 
														int preference, int size){
	create_link_entry(&(*list), initial_node, final_node, preference);	
	return;
}


void Read_file(char * ficheiroIn, node**list, int*size){
	FILE*fp;
	int initial_node, final_node, preference;
	(*size)=positions(ficheiroIn);
	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    (*list)=malloc((*size)*sizeof(node));
    if((*list)==NULL)printf("ERROR IN MALLOC\n");
	int i=0;
	for(i=0; i<(*size); i++){
		((*list)[i]).link=NULL;
	}
    while(get_table_line(&initial_node, &final_node, &preference, fp)==0){
		list_adj(&(*list), initial_node, final_node, preference, (*size));
	}
	fclose(fp);
	return;
}
