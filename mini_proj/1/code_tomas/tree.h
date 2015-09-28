typedef struct _node{
	
	int next_hop;
	struct _node * zero;
	struct _node * one;
	
}node;

node * initialize_node();
void creates_root(node * n, int next_hop);
void receive_node(node * root, char * prefix, int next_hop);
