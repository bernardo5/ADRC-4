#include "lista_adjacencias.h"

int get_table_line(int * initial_node, int *final_node , int*preference, FILE*fp){
	if(fscanf(fp, "%d %d %d", initial_node, final_node, preference)!=3){
		return -1;
	}
	return 0;
}

void create_node_entry(node**n, int initial_node){
		(*n)=(node*)malloc(sizeof(node));
		(*n)->identifier=initial_node;
		(*n)->next=NULL;
		(*n)->link=NULL;
		return;
}

void create_link_entry(node**n, int final_node, int preference){
		adj_node * temp=(adj_node*)malloc(sizeof(adj_node));
		temp->identifier=final_node;
		temp->preference=preference;
		if((*n)->link==NULL){/*first element*/
			(*n)->link=temp; 
		}else{/*the list has elements*/
			if((temp->preference) < ((*n)->link->preference)){
				adj_node*insert_aux;
				for(insert_aux=(*n)->link;(insert_aux->next!=NULL)
						&&(temp->preference < insert_aux->next->preference);
											insert_aux=insert_aux->next);
				temp->next=insert_aux->next;
				insert_aux->next=temp;
			}else{
				temp->next=(*n)->link;
				(*n)->link=temp;
			}
		}
		
		
		/*temp->next=(*n)->link;
		(*n)->link=temp;*/
		return;
}

void list_adj(node**list, int initial_node, int final_node, 
														int preference){
	if(*list==NULL){
		/*creates node and respective link*/
		create_node_entry(&(*list), initial_node);	
		create_link_entry(&(*list), final_node, preference);	
	}else{
		node*aux;
		for(aux=(*list); (aux->identifier!=initial_node) && (aux->next!=NULL); 
				aux=aux->next);
				
				
		if(aux->identifier==initial_node){
				 create_link_entry(&aux, final_node, preference);
				 
		}else{
			if(aux->next==NULL){
				/*there is no node in the list*/
				create_node_entry(&(aux->next), initial_node);	
				create_link_entry(&(aux->next), final_node, preference);
			}
		}
		
	}
	/* */
	return;
}


void Read_file(char * ficheiroIn, node**list){
	FILE*fp;
	int initial_node, final_node, preference;
	
	fp = fopen( ficheiroIn , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERROR! Cannot open file: %s!\n", ficheiroIn);
		exit ( 1 );
    }
    node*aux;
    while(get_table_line(&initial_node, &final_node, &preference, fp)==0){
		list_adj(&(*list), initial_node, final_node, preference);
	}

	return;
}
