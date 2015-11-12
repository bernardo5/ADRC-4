#include "statistics.h"


void paths_count(int count_nodes, int*node_distance, float *ones, float* twos, float *threes, float*unusable){
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
					if(node_distance[i]==-1){
						(*unusable)++;
					}
				}
			}
		}
	}	
	return;
}

void hops_count(int**stat_hops, int*node_hops, int size){
	int i;
	
	for(i=0; i<size; i++){
		if((node_hops[i]>0)&&(node_hops[i]<50)){
			(*stat_hops)[node_hops[i]]++;
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


void paths_statistics(float *stat_customer, float *stat_peer, float *stat_provider, int count_nodes, float ones, float twos, float threes, float unusable){
	(*stat_customer)=ones/(ones+twos+threes+unusable/*(count_nodes-1)*count_nodes*/);
	(*stat_peer)=twos/(ones+twos+threes+unusable/*(count_nodes-1)*count_nodes*/);
	(*stat_provider)=threes/(ones+twos+threes+unusable/*(count_nodes-1)*count_nodes*/);
	printf("Unusable: %f\n", unusable/(ones+twos+threes+unusable/*(count_nodes-1)*count_nodes*/));
	return;
}

void number_hops_statistics(int*stat_hops){
	int i;
	float total=0;
	
	/*count the total number of hops*/
	for(i=0;i<50;i++){
		if(stat_hops[i]!=0)total=total+stat_hops[i];
	}
	
	for(i=0;i<50;i++){
		if(stat_hops[i]!=0)printf("%d hops statistics=%f\n", i, (stat_hops[i])/total);
	}
	
	return;
}
