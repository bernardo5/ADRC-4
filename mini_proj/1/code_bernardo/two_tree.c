#include "two_tree.h"

int leaf_check(node*base_node){
	if((base_node->zero==NULL)&& (base_node->one==NULL)){
		return 1;
	}else{
		return 0;
	}
}

int child_check(node*base_node){
	/*cant be both otherwise leaf_check=1*/
	if((base_node->zero)==NULL){
		return 0;
	}
	if((base_node->one)==NULL){
		return 1;
	}
	/*if none are null there is no need to allocate a new child*/
	return -1;

}

int update_next_hop(node*base_node, int next_hop){
	if((base_node->next_hop)!=-1){
		/*change the value*/
		return (base_node->next_hop);
	}
	return next_hop;	
}


void convert_tree(node**base_node, int next_hop){
	if(leaf_check(*base_node)==1){ /*leaf case*/
		if(((*base_node)->next_hop)==-1){ /*need to update node value*/
			((*base_node)->next_hop)=next_hop;
		}
	}else{ /*middle node case*/
		int check=child_check(*base_node);
		char*new_prefix=malloc(sizeof(char)*(strlen((*base_node)->prefix)+strlen("1")+1));
		if(check==0){
			strcpy(new_prefix, (*base_node)->prefix);
			strcat(new_prefix, "0");
			(*base_node)->zero=Initialize_node(new_prefix);
		}else{
			if(check==1){
				strcpy(new_prefix, (*base_node)->prefix);
				strcat(new_prefix, "1");
				(*base_node)->one=Initialize_node(new_prefix);
			}
		}
		convert_tree(&((*base_node)->zero), update_next_hop(*base_node, next_hop));
		convert_tree(&((*base_node)->one), update_next_hop(*base_node, next_hop));
		free(new_prefix);
	}
	return;
}

int verify_address(char*address){
	int i;
	
	for(i=0;i<strlen(address);i++){
		if((address[i]!='0')&&(address[i]!='1'))return -1;
	}
	return 1;
}

int AddressLookUp(node*root, char*address){
	if(verify_address(address)==-1) return -1;
	int bit=0;
	node*auxiliar=root;
	while(bit<strlen(address)){
				if(address[bit]=='0'){
					if((auxiliar->zero)==NULL){
						return auxiliar->next_hop;
					}
					auxiliar=auxiliar->zero;
				}else{
					if((auxiliar->one)==NULL){
						return auxiliar->next_hop;
					}	
					auxiliar=auxiliar->one;
				}
				bit++;
	}
	return -1;	
}
