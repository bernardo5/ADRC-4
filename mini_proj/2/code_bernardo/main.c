#include "lista_adjacencias.h"


int main(int argc, char**argv){
	FILE*fp;
	char * ficheiroIn;
	node*list=NULL;
	
	if(argc<2){
		printf("too few arguments\n");
		exit(-1);
	}
	ficheiroIn = argv[1];
	
	Read_file(ficheiroIn, &list);
	
	node*aux;
	adj_node*aux_adj;
	for(aux=list;aux!=NULL;aux=aux->next){
		for(aux_adj=aux->link;aux_adj!=NULL; aux_adj=aux_adj->next) printf("%d %d %d\n\n", aux->identifier, aux_adj->identifier, aux_adj->preference);
	}
	
	exit(0);
}
