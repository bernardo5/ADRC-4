#include "file.h"

typedef struct _node{
	int next_hop;
	struct _node*zero;
	struct _node*one;
}node;

node*Init_tree();

node* Initialize_node();

