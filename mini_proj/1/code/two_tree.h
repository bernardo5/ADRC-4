#include "tree.h"


int leaf_check(node*base_node);

int child_check(node*base_node);

int update_next_hop(node*base_node, int next_hop);

void TwoTree(node**base_node, int next_hop);

int AddressLookUp(node*root, char*address);

void PrintTable(node*base_node, char*prefix, int look_up_control);
