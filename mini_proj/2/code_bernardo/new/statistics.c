#include "statistics.h"


void paths_statistics(float *stat_customer, float *stat_peer, float *stat_provider, int count_nodes, int*node_distance){
	int i;
	float ones=0;
	float twos=0;
	float threes=0;
	
	for(i=0; i<count_nodes; i++){
		if(node_distance[i]==1){
			ones++;
		}else{
			if(node_distance[i]==2){
				twos++;
			}else{
				if(node_distance[i]==3){
					threes++;
				}else{
					/*no path*/
				}
			}
		}
	}
	(*stat_customer)=ones/count_nodes;
	(*stat_peer)=twos/count_nodes;
	(*stat_provider)=threes/count_nodes;
	
	return;
}
