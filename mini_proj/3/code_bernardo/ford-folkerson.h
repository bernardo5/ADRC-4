#include "file.h"

typedef struct _element{
	int number;
	int signal; /*0 if minus, 1 if plus*/
	struct _element*next;	
}element;

typedef struct _FIFO{
	element*first;
	element*last;	
}FIFO;

typedef struct _disc{
	int minus;
	int plus;
}disc;

element* FIFONew(int number, int signal, element *pNext);

FIFO* FIFOInit();

void FIFOPut(FIFO *pFIFO, int number, int signal);

int FIFOGet(FIFO *pFIFO);

void init_vector(int**vector, int size);

disc* BFS(int initial, node*list, int **parent, int size);

void FordFulkerson(node**list, int size, int **parent, int initial_node, int final_node);
