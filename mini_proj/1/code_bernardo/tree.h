#include "file.h"

typedef struct _node{
	int next_hop;
	struct _node*zero;
	struct _node*one;
}node;

node*Init_tree();

node* Initialize_node();

void AddPrefix(node**root, char*prefix, int next_hop);

void ReadTable(node**root, char*table_txt);

