#include "lista_adjacencias.h"

void paths_count(int count_nodes, int*node_distance, float *ones, float* twos, float *threes, float*unusable);

void hops_count(int**stat_hops, int*node_hops, int size);

int count_number_nodes(node*list, int size);

void paths_statistics(float *stat_customer, float *stat_peer, float *stat_provider, int count_nodes, float ones, float twos, float threes, float unusable);

void number_hops_statistics(int*stat_hops);
