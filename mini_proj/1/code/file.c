#include "file.h"

void get_table_line(char**prefix, int*next_hop, FILE*fp){
	if(fscanf(fp, "%s %d", *prefix, next_hop)!=2){
		printf("Error: %s\n", strerror(errno));
	}
	return;
}

