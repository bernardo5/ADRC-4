#include "tree.h"


int leaf_check(node*base_node);

int child_check(node*base_node);

int update_next_hop(node*base_node, int next_hop);

void convert_tree(node**base_node, int next_hop);

int verify_address(char*address);

int AddressLookUp(node*root, char*address);
