
#include "statistics.h"
#include "heap.h"

int min(int i, int n);

void insert(int identifier, dij_node**list);

int empty_queue(dij_node*visited_nodes);

int identifier_smaller_distance(int**heap_place, node*list, int*node_distance, int*node_hops, int count_nodes, dij_node**visited_nodes);

void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, dij_node ** visited_nodes, int**heap_place);

void Dijkstra(node*list, int destiny, int count_nodes, int**node_distance, int**node_hops);
