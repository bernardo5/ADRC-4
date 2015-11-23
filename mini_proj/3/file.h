#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	int identifier;
	struct _node * next;
	struct _adj_node * link;
}node;

typedef struct _adj_node{
	int identifier;
	struct _adj_node * next;
}adj_node;

void create_link_entry(node**n, int initial_node, int final_node);

int get_table_line(int * initial_node, int * final_node, FILE*fp);

void list_adj(node**list, int initial_node, int final_node);

void Read_file(char * ficheiroIn, node**list);
