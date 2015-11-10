#include "statistics.h"


void paths_count(int count_nodes, int*node_distance, float *ones, float* twos, float *threes){
	int i;
		
	for(i=0; i<count_nodes; i++){
		if(node_distance[i]==1){
			(*ones)++;
		}else{
			if(node_distance[i]==2){
				(*twos)++;
			}else{
				if(node_distance[i]==3){
					(*threes)++;
				}else{
					/*no path*/
				}
			}
		}
	}	
	return;
}

int count_number_nodes(node*list, int size){
	int count_nodes=0;
	int i;
	for(i=0; i<size;i++){
		if((list[i].link)!=NULL){
			count_nodes++;
		}
	}
	
	return count_nodes;
}


void paths_statistics(float *stat_customer, float *stat_peer, float *stat_provider, int count_nodes, float ones, float twos, float threes){
	(*stat_customer)=ones/((count_nodes-1)*count_nodes);
	(*stat_peer)=twos/((count_nodes-1)*count_nodes);
	(*stat_provider)=threes/((count_nodes-1)*count_nodes);
	return;
}

/*void number_hops_statistics(int count_nodes, int*node_hops, float * stat_hops){
	int i;
	float sum=0;
	for(i=0; i<count_nodes;i++){
		sum=sum+(node_hops)[i];
		if((node_hops)[i]==50000){
			i=count_nodes;
			sum=50000;
		}
	}
	if(sum==50000){
		(*stat_hops)=50000;
	}else{
		(*stat_hops)=sum/count_nodes;
	}
	return;
}*/
