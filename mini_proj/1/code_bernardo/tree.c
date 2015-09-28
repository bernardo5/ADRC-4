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

void create_node(node*new, node*just_created){
	new=just_created;
	return;
}



void ReadTable(char*table_txt){
	
	char *prefix=malloc(10*sizeof(char));
	int next_hop;
	FILE*fp;
	
	/*file opening*/
	fp = fopen( table_txt , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "Error, cannot open file: %s!\n", table_txt);
		exit ( 1 );
    }
	
	/*Tree initialization with the root pointer*/
	node*root=Init_tree();
	
	if(root==NULL)printf("Table successfully initialized\n");
	
	root = Initialize_node();	
	
	while(get_table_line(&prefix, &next_hop, fp)==0){
		/*the prefix read can be * for empty prefixes
		 * or a bit sequence*/
		 printf("%s\t%d\n", prefix, next_hop);
		if(strcmp(prefix, "*")==0){
			printf("empty prefix\n");
			root->next_hop=next_hop;
			printf("Next hop root is: %d\n", root->next_hop);
		}else{
			
		}
	}
	
	fclose(fp);
	return;
}


