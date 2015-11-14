#include "statistics.h"
#include "heap.h"

int min(int i, int n);

int table(int u, int uv);

void Initialize_distance_matrix(int count_nodes, int**node_distance, int**node_hops, node *list, int destiny, Heap*h, int**heap_place);

void invert_weights(int**node_distance, int count_nodes);

void Dijkstra(node*list, int destiny, int count_nodes, int**node_distance, int**node_hops);
