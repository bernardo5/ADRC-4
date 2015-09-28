#include "file.h"

int main(){
	
	char *prefix=malloc(10*sizeof(char));
	int next_hop;
	FILE*fp;
	
	fp = fopen( "teste_enunciado.txt" , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "ERRO! nao e possivel abrir o ficheiro: %s!\n", "teste_enunciado.txt");
		exit ( 1 );
    }
	
	while(get_table_line(&prefix, &next_hop, fp)==0){
		printf("%s\t%d\n", prefix, next_hop);
	}
	
	
	fclose(fp);
	
	exit(0);
}
