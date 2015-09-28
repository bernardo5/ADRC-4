#include "file.h"
#include "tree.h"

node * initialize_node(){

	node * n=malloc(sizeof(node));
	n->next_hop=-1;
	n->zero=NULL;
	n->one=NULL;
	
	return n;
	
}
