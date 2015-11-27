#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	struct _adj_node * minus;
	struct _adj_node * plus;
}node;

typedef struct _adj_node{
	int identifier;
	int capacity;
	struct _adj_node * next;
}adj_node;

void create_link_entry(node**n, int initial_node, int final_node);

int get_table_line(int * initial_node, int * final_node, FILE*fp);

void list_adj(node**list, int initial_node, int final_node);

int Read_file(char * ficheiroIn, node**list);
