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

void AddPrefix(node**root, char*prefix, int next_hop){
	/*the prefix read can be * for empty prefixes
		 * or a bit sequence*/
		 printf("%s\t%d\n", prefix, next_hop);
		if(strcmp(prefix, "*")==0){
			(*root)->next_hop=next_hop;
		}else{
			int bit=0;
			node*auxiliar=(*root);
			while(bit<strlen(prefix)){
				if(prefix[bit]=='0'){
					
					if((auxiliar->zero)==NULL){
						if(next_hop!=-1){
							(auxiliar->zero)=Initialize_node();
						}else{
							printf("Prefix does not exist\n");
							return;
						}
					}
					auxiliar=auxiliar->zero;
				}else{
					if((auxiliar->one)==NULL){
						if(next_hop!=-1){
							(auxiliar->one)=Initialize_node();
						}else{
							printf("Prefix does not exist\n");
							return;
						}
					}	
					auxiliar=auxiliar->one;
				}
				bit++;
			}
			auxiliar->next_hop=next_hop;
		}
	return;
}

void DeletePrefix(node**root, char*prefix){
	AddPrefix(root, prefix, -1);
	return;
}


void ReadTable(node**root, char*table_txt){
	
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
	
	(*root) = Initialize_node();	
	
	while(get_table_line(&prefix, &next_hop, fp)==0){
		AddPrefix(root, prefix, next_hop);
	}
	fclose(fp);
	return;
}


