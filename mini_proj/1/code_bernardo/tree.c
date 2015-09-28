#include "tree.h"

node*Init_tree(){
	node*aux=NULL;
	return aux;
}


node* Initialize_node(){
	node*n=malloc(sizeof(node));
	n->next_hop=-1; /*no hop specified*/
	n->zero=NULL;
	n->one=NULL;
	return n;
}



void ReadTable(){
	
	char *prefix=malloc(10*sizeof(char));
	int next_hop;
	FILE*fp;
	
	/*file oppening*/
	fp = fopen( table_txt , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "Error, cannot open file: %s!\n", table_txt);
		exit ( 1 );
    }
	
	/*Tree initialization with the root pointer*/
	node*root=Init_tree();
	
	if(root==NULL)printf("Table successfully initialized\n");
	
	while(get_table_line(&prefix, &next_hop, fp)==0){
		
	}
	
	fclose(fp);
	return;
}


