#include "two_tree.h"

/*returns 1 if the node is a leaf*/
int leaf_check(node*base_node){
	if((base_node->zero==NULL)&& (base_node->one==NULL)){
		return 1;
	}else{
		return 0;
	}
}

/*returns 0 or 1 if there is need of adding a node struct in the tree conversion*/
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

/*returns the next hop value that the specified prefix will have*/
int update_next_hop(node*base_node, int next_hop){
	if((base_node->next_hop)!=-1){
		/*change the value*/
		return (base_node->next_hop);
	}
	return next_hop;
}


void TwoTree(node**base_node, int next_hop){
	if(leaf_check(*base_node)==1){ /*leaf case*/
		if(((*base_node)->next_hop)==-1){ /*need to update node value*/
			((*base_node)->next_hop)=next_hop;
		}
	}else{ /*middle node case*/
		int check=child_check(*base_node);
		if(check==0){/*need to create a new node*/
			(*base_node)->zero=Initialize_node();
		}else{
			if(check==1){/*need to create new node*/
				(*base_node)->one=Initialize_node();
			}
		}
		TwoTree(&((*base_node)->zero), update_next_hop(*base_node, next_hop));
		TwoTree(&((*base_node)->one), update_next_hop(*base_node, next_hop));
	}
	return;
}

int AddressLookUp(node*root, char*address){
	if(verify_address(address)==-1) return -1;
	/*only continues if the address is valid*/
	int bit=0;
	node*auxiliar=root;
	/*while its possible goes has far as possible in the tree*/
	while(bit<strlen(address)){
				if(address[bit]=='0'){
					if((auxiliar->zero)==NULL){/*reached as far as possible*/
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
	
	return auxiliar->next_hop;
}
