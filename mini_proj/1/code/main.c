#include "file.h"

int main(int argc, char *argv[]){
	
	if(argc!=2){
		printf("Specify the file name\n");
		exit(-1);
	}
	
	char *table_txt=argv[1];
	
	char *prefix=malloc(10*sizeof(char));
	int next_hop;
	FILE*fp;
	
	fp = fopen( table_txt , "r");
	if ( fp == NULL ) {
		fprintf ( stderr, "Error, cannot open file: %s!\n", table_txt);
		exit ( 1 );
    }
	
	while(get_table_line(&prefix, &next_hop, fp)==0){
		printf("%s\t%d\n", prefix, next_hop);
	}
	
	
	fclose(fp);
	
	exit(0);
}
