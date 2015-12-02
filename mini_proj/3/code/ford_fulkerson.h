#include "file.h"

typedef struct _element{
	int number;
	int signal;
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

void init_vector(int ** vector, int size, int parameter);

void init_vector_disc(disc**vector, int size);

disc * BFS(node * list, int initial_node, int ** parent, int size);

int path(int initial_node, int final_node, int * parent);

int ford_fulkerson(node ** list, int size, int ** parent, int initial_node, int final_node, char ** connectivity, int * min);
