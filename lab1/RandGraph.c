#include <stdio.h>
#include <stdlib.h>
#include "GraphADT.h"

int main(int argc, char *argv[]) {
	char	s[] = "RandGraph.gle";
	int		V = atoi(argv[1]), E = atoi(argv[2]);
	Graph	G = GRAPHrandp(V, E);

	GRAPHplot(G, s);
	if (V < 20)
		GRAPHshow(G);
	else 
		printf("%d vertices, %d edges, ", V, E);
	return 0;
}