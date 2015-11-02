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
