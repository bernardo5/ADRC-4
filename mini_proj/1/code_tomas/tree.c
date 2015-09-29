#include "file.h"
#include "tree.h"

node * initialize_node(){

	node * n=malloc(sizeof(node));
	n->next_hop=-1;
	n->zero=NULL;
	n->one=NULL;
	
	return n;
	
}

void creates_root(node * n, int next_hop){
	
	n->next_hop=next_hop;
	n->zero=NULL;
	n->one=NULL;
	
	return;
	
}

void receive_node(node * root, char * prefix, int next_hop){
	
	int i;
	
	node * n;
	node * temp;
	node * blank_node;
	n=initialize_node();
	n->next_hop=next_hop;
	
	temp=root;
	
	for(i=0; prefix[i]<50 && prefix[i]>47; i++){
	
		/*ser um 0*/
		if(prefix[i]==48){
			if(prefix[i+1]>49 || prefix[i+1]<48){
					temp->zero=n;
			}else{
				if(temp->zero==NULL){
					blank_node=initialize_node();
					temp->zero=blank_node;
					temp=blank_node;
				}else{
					temp=temp->zero;
				}
			}
			
		/*ser um 1*/
		}else if(prefix[i]==49){
			if(prefix[i+1]>49 || prefix[i+1]<48){
				temp->one=n;
			}else{
				if(temp->one==NULL){
					blank_node=initialize_node();
					temp->one=blank_node;
					temp=blank_node;
				}else{
					temp=temp->one;
				}
			}
		}		
	}
}

void print_tree_vec(node * root){
	
	node * temp=root;
	
	while((temp->one!=NULL)&&(temp->zero!=NULL)){
	
	
	
	}
	
}
