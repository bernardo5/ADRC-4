#include "file.h"

int get_table_line(FILE * fp, char ** prefix, int * next_hop){

	if(fscanf(fp, "%s %d", *prefix, next_hop)!=2){return -1;}
	return 0;
	
}
