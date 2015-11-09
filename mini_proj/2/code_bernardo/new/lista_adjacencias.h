#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _adj_node{
	int identifier;
	int preference;
	struct _adj_node * next;
}adj_node;

typedef struct _node{
	struct _adj_node * link;
}node;

int positions(char * ficheiroIn);

int get_table_line(int * initial_node, int *final_node , int*preference, FILE*fp);

void create_link_entry(node**n, int initial_node, int final_node, int preference);

void list_adj(node**list, int initial_node, int final_node, 
														int preference, int size);
														
void Read_file(char * ficheiroIn, node**list, int*size);
