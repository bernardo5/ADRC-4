#include "ford_fulkerson.h"

void cumulative_statistics(int * vector, int size){
	
	int i;
	float cumulative = 0;
	
	//printf("THERE ARE %d PAIRS OF NODES DIRECTLY CONNECTED\n", vector[0]/2);
	
	for(i=1; i<size; i++){
		cumulative = cumulative + vector[i];
	}
	
	printf("THE CUMULATIVE DISTRIBUTION, FOR EVERY NATURAL \"K\" IS THE FOLLOWING:\n");
	
	for(i=1; i<size; i++){
		printf("%d WITH PROBABILITY %f\n", i, vector[i]/cumulative);
	}
	
}

int main(int argc, char**argv){
	
	char * ficheiroIn;
	char * connectivity = malloc(100*sizeof(char));
	node * list;
	int option;
	int initial_node, final_node;

	if(argc<2){
		printf("TOO FEW ARGUMENTS\n");
		exit(-1);
	}
	
	printf("PLEASE CHOOSE AN OPTION \n");
	printf("1. CALCULATE THE NODES SEPARATING NODE A FROM B\n");
	printf("2. CALCULATE STATISTICS AND CONNECTIVITY OF THE GRAPH\n");
	
	if(scanf("%d", &option)!=1){
		printf("ERROR: SPECIFY A VALID SOURCE AND DESTINATION\n");
		exit(0);
	}	

		ficheiroIn = argv[1];
		
		int size = Read_file(ficheiroIn, &list);
		
		/*********************VECTOR DE ESTATISTICAS***************************/
		
		int * node_statistics = malloc(size*sizeof(int));
		
		init_vector(&node_statistics, size, 0);
		
		int * parent = malloc(size*sizeof(int));

		/**********************************************************************/
		int min = 100;	
		
		//ONE SOURCE ONE DESTINATION
		if(option == 1){
			printf("PLEASE CHOOSE A SOURCE AND DESTINATION.\n");

			if(scanf("%d %d", &initial_node, &final_node)!=2){
				printf("ERROR: SPECIFY A VALID SOURCE AND DESTINATION\n");
				exit(0);
			}
			if(contiguous(list, initial_node, final_node)!=0) printf("THERE IS NO WAY OF SEPARATING NODE %d FROM NODE %d BECAUSE THEY ARE CONTIGUOUS\n", initial_node, final_node);
			else printf("FOR SPECIFIED SET OF NODES, IS NECESSARY TO TAKE %d NODE(S) WHICH IS/ARE:%s\n", ford_fulkerson(&list, size, &parent, initial_node, final_node, &connectivity, min), connectivity);
			
		//STATISTICS
		}else if(option == 2){

			int colum;
			int row;
			
			
			for(colum=0; colum<size; colum++){
				for(row=0; row<size; row++){
					if(row!=colum){
						if(contiguous(list, colum, row)!=0){
							(node_statistics[0]) ++;
						}else{
							(node_statistics[ford_fulkerson(&list, size, &parent, colum, row, &connectivity, min)]) ++;
							Read_file(ficheiroIn, &list);
						}
					}
				}
			}
			
			cumulative_statistics(node_statistics, size);
			printf("IF YOU TAKE THE NODE(S)%s THE GRAPH WILL SPLIT\n", connectivity);
		
		}else{
			printf("PLEASE CHOOSE A VALID OPTION\n");
		}
		
	exit(0);
}
