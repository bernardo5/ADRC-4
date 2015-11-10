#include "dijkstra.h"

void paths_count(int count_nodes, int*node_distance, float *ones, float* twos, float *threes);

int count_number_nodes(node*list, int size);

void paths_statistics(float *stat_customer, float *stat_peer, float *stat_provider, int count_nodes, float ones, float twos, float threes);

void number_hops_statistics(int count_nodes, int*node_hops, float * stat_hops);
