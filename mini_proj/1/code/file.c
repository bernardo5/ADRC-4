#include "file.h"

int get_table_line(char**prefix, int*next_hop, FILE*fp){
	if(fscanf(fp, "%s %d", *prefix, next_hop)!=2){
		return -1;
	}
	return 0;
}

