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
	n=initialize_node();
	
	temp=root;
	
	for(i=0; prefix[i]<50 && prefix[i]>47; i++){
	
		/*ser um 0*/
		if(prefix[i]==48){
			if(temp->zero==NULL){
				temp->zero=n;
			}else{
				temp=temp->zero;
			}
			
		/*ser um 1*/
		}else if(prefix[i]==49){
			if(temp->one==NULL){
				temp->one=n;
			}else{
				temp=temp->one;
			}
		}		
	}
}
