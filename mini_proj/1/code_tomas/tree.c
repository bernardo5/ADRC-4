#include "tree.h"

node*Init_tree(){
	node*aux=NULL;
	return aux;
}


node*Initialize_node(){
	node*n=malloc(sizeof(node));
	n->next_hop=-1; /*no hop specified*/
	n->zero=NULL;
	n->one=NULL;
	return n;
}

void Free_Node(node*base_node){
	
	free(base_node->prefix);
	free(base_node);
	
	return;
}

char*NewPrefix(char*prefix){
	
	prefix++;
	
	return prefix;
}

void AddPrefix(node**root, char*prefix, int next_hop){
	/*the prefix read can be * for empty prefixes
		 * or a bit sequence*/
		if(strcmp(prefix, "*")==0){
			(*root)->next_hop=next_hop;
			(*root)->prefix=malloc(sizeof(char)*strlen(prefix)+1);
			strcpy((*root)->prefix, prefix);
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
			auxiliar->prefix=malloc(sizeof(char)*strlen(prefix)+1);
			strcpy(auxiliar->prefix, prefix);
		}
	return;
}

int DeletePrefix(node**base_node, char*prefix){
	
	/*AddPrefix(root, prefix, -1); versao apagar sem frees*/
	
	if(strlen(prefix)>0){
	
		if(prefix[0]=='0'){
			prefix=NewPrefix(prefix);
			/*verificar que existe no*/
			if((*base_node)->zero!=NULL){
				if((DeletePrefix((&(*base_node)->zero), prefix))==1){
					(*base_node)->zero=NULL;
				}
			}
			else{
				printf("Prefix doesn't exist\n");
				exit(1);
			}
			
			
			
		}else if(prefix[0]=='1'){
			prefix=NewPrefix(prefix);
			if((*base_node)->one!=NULL){
				if((DeletePrefix((&(*base_node)->one), prefix)==1)){
					(*base_node)->one=NULL;
				}
			}else{
				printf("Prefix doesn't exist\n");
				exit(1);
			}
		}
	}
	
	
	else if(strlen(prefix)==0){
	/*chegamos ao destino*/
		if((*base_node)->zero==NULL && (*base_node)->one==NULL){
			Free_Node(*base_node);
			return 1;
		}else{
			(*base_node)->next_hop=-1;
		}	
	}
	
	return 0;
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

void PrintTable(node*base_node){
	if((base_node->next_hop)!=-1){
		printf("%s\t%d\n", base_node->prefix, base_node->next_hop);
	}
	if(base_node->zero!=NULL){
		PrintTable(base_node->zero);
	}
	if(base_node->one!=NULL){
		PrintTable(base_node->one);
	}
	return;
}


