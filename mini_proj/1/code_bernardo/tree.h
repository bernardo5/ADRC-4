#include "file.h"

typedef struct _node{
	int next_hop;/*value if it has info, -1 if its just a path node*/
	char * prefix;
	struct _node*zero;
	struct _node*one;
}node;

node*Init_tree();

node* Initialize_node(char*prefix);

void AddPrefix(node**root, char*prefix, int next_hop);

char*NewPrefix(char*prefix);

void Free_Node(node*base_node);

int DeletePrefix(node**root, char*prefix);

void ReadTable(node**root, char*table_txt);

void PrintTable(node*base_node);

void PosFixed_delete_tree(node** base_node);

