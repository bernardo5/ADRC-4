#include "lista_adjacencias.h"

typedef struct _dij_node{
	struct _dij_node * next;
	int identifier;
}dij_node;


void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, dij_node**visited_nodes);

int identifier_smaller_distance(int*node_distance, int*node_hops, int count_nodes, dij_node*visited_nodes);

void remove_element_from_queue(dij_node**unvisited_nodes, int dijkstra_identifier);

int verify_node_unseen(int node_identifier, dij_node*unvisited_nodes);

int empty_queue(dij_node*visited_nodes);

void Dijkstra(node*list, int destiny, int count_nodes, int**node_distance, int**node_hops);
