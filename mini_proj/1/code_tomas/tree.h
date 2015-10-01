#include "file.h"

typedef struct _node{
	int next_hop;
	char * prefix;
	struct _node*zero;
	struct _node*one;
}node;

node*Init_tree();

node*Initialize_node();

char*NewPrefix(char*prefix);

void Free_Node(node*base_node);

void AddPrefix(node**root, char*prefix, int next_hop);

void DeletePrefix(node**root, char*prefix);

void ReadTable(node**root, char*table_txt);

void PrintTable(node*base_node);

