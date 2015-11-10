
#include "statistics.h"
#include "heap.h"




void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, Heap**h);

void Dijkstra(node*list, int destiny, int count_nodes, int**node_distance, int**node_hops);
