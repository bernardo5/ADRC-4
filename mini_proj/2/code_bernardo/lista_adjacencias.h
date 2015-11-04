#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _adj_node{
	int identifier;
	int preference;
	struct _adj_node * next;
}adj_node;

typedef struct _node{
	int identifier;
	struct _adj_node * link;
	struct _node*next;
}node;


int get_table_line(int * initial_node, int *final_node , int*preference, FILE*fp);

void create_node_entry(node**n, int initial_node);

void create_link_entry(node**n, int final_node, int preference);

void list_adj(node**list, int initial_node, int final_node, 
														int preference);
														
void Read_file(char * ficheiroIn, node**list);
