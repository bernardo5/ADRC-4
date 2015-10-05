#include "file.h"

/* This function has the purpose to read a line from the file given and
*store the prefix and next hop values into the respective variables*/

int get_table_line(char**prefix, int*next_hop, FILE*fp){
	if(fscanf(fp, "%s %d", *prefix, next_hop)!=2){
		return -1;
	}
	return 0;
}

