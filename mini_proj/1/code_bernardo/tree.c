#include "tree.h"

/*This function has the purpose of initializing the pointer that will be
*the root of the tree*/

/*verifies if the address specified is a valid prefix*/
int verify_address(char*address){
	int i;

	for(i=0;i<strlen(address);i++){
		if((address[i]!='0')&&(address[i]!='1')) return -1;
	}
	return 1;
}


node*Init_tree(){
	node*aux=NULL;
	return aux;
}

/*This function has the purpose of creating and initializing
*a new node.
*this might happen when inserting a new prefix, converting a forwarding
*table into a binary prefix tree representation or in a convertion from binary prefix
*prefix tree into a binary prefix 2-tree*/

node* Initialize_node(char*prefix){
	node*n=malloc(sizeof(node));
	n->next_hop=-1; /*no hop specified*/
	n->zero=NULL;
	n->one=NULL;
	n->prefix=malloc(sizeof(char)*(strlen(prefix)+1));
	strcpy(n->prefix, prefix);
	return n;
}

/*Function that adds a new prefix into a binary prefix tree*/

void AddPrefix(node**root, char*prefix, int next_hop){
	
	if((verify_address(prefix)==-1)&&strcmp("*", prefix)!=0){
		printf("Invalid prefix\n");
		 return;
	}
	/*the prefix read can be * for empty prefixes
		 * or a bit sequence*/

		 /*this variable will be used to store the path already covered
		 *it will be copied into a node structure, to make the table printing easier*/
		char* current_prefix=malloc(sizeof(char)*(strlen(prefix)+1));
		current_prefix[0] = '\0';
        /*if the prefix specified is the root some storage information has no use
        *for ex:prefix(has none), no need of covering a tree path, etc*/
		if(strcmp(prefix, "*")==0){
			(*root)->next_hop=next_hop;
			strcpy((*root)->prefix, prefix);
		}else{
		    /*in this point, we have the necessity of covering a tree path which will
		    *depend on the prefix given*/
			int bit=0; /*will define which prefix bit we should analyze*/
			node*auxiliar=(*root); /*auxiliar pointer that will go through the tree*/
			while(bit<strlen(prefix)){ /*while we havent reached th end of the path specified by the prefix*/
				if(prefix[bit]=='0'){
					strcat(current_prefix, "0");
					if((auxiliar->zero)==NULL){/*if the node doesnt exist its necessary to create it*/
						(auxiliar->zero)=Initialize_node(current_prefix);/*node creation with the prefix specification*/
                    }
					auxiliar=auxiliar->zero;
				}else{
					strcat(current_prefix, "1");
					if((auxiliar->one)==NULL){
                        (auxiliar->one)=Initialize_node(current_prefix);
                    }
					auxiliar=auxiliar->one;
				}
				bit++;
			}
			/*copying the prefix values into the node*/
			auxiliar->next_hop=next_hop;
		}
	free(current_prefix);/*free of the auxiliar string used*/
	return;
}

/*function that frees a certain node*/

void Free_Node(node*base_node){

	free(base_node->prefix);
	free(base_node);

	return;
}

/*function that updates the prefix string "deleting" what has already been processed*/

char*NewPrefix(char*prefix){

	prefix++;

	return prefix;
}

int DeletePrefix(node**base_node, char*prefix){
    /*its not supposed to delete the root*/
		if((verify_address(prefix)==-1)&&strcmp("*", prefix)!=0){
		printf("Invalid prefix\n");
		 return -1;
	}
    /*if we havent reached the end of the string we havent reached the node we wanted to delete*/
	if(strlen(prefix)>0){
		if(prefix[0]=='0'){
			prefix=NewPrefix(prefix);
			/*verify if the node exists*/
			if((*base_node)->zero!=NULL){
				if((DeletePrefix((&(*base_node)->zero), prefix))==1){
                    /*if the child has been deleted the pointer is now NULL*/
					(*base_node)->zero=NULL;
				}
			}
			else{
				printf("Prefix doesn't exist\n");
				return -1;
			}
		}else if(prefix[0]=='1'){
			prefix=NewPrefix(prefix);
			if((*base_node)->one!=NULL){
				if((DeletePrefix((&(*base_node)->one), prefix)==1)){
					(*base_node)->one=NULL;
				}
			}else{
				printf("Prefix doesn't exist\n");
				return -1;
			}
		}
	}


	else if(strlen(prefix)==0){
	/*we reached the node to be deleted*/
		if((*base_node)->zero==NULL && (*base_node)->one==NULL){
			/*the node has no children so we can free its memory*/
			Free_Node(*base_node);
			return 1;
		}else{
		    /*the node has at least a child so we just say it has no next hop*/
			(*base_node)->next_hop=-1;
		}
	}

	return 0;
}


void ReadTable(node**root, char*table_txt){
    /*its said that we can assume addresses have 8 bits rather than 32*/
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

	(*root) = Initialize_node("*");
    /*while the file has info, we will had it to the tree*/
	while(get_table_line(&prefix, &next_hop, fp)==0){
		AddPrefix(root, prefix, next_hop);
	}
	free(prefix);
	fclose(fp);
	return;
}

void PrintTable(node*base_node){
	if((base_node->next_hop)!=-1){/*the prefix of the node visited has a next hop info*/
		printf("%s\t%d\n", base_node->prefix, base_node->next_hop);
	}
	if(base_node->zero!=NULL){/*if it has a child this way, analyses its sub-tree*/
		PrintTable(base_node->zero);
	}
	if(base_node->one!=NULL){/*if it has a child this way, analyses its sub-tree*/
		PrintTable(base_node->one);
	}
	return;
}


void PosFixed_delete_tree(node** base_node){
  if((*base_node)==NULL) return;
  PosFixed_delete_tree(&(*base_node)->zero);
  PosFixed_delete_tree(&(*base_node)->one);
  Free_Node(*base_node);
  return;
}

