#include "file.h"

typedef struct _element{
	int number;
	struct _element*next;	
}element;

typedef struct _FIFO{
	element*first;
	element*last;	
}FIFO;

element* FIFONew(int number, element *pNext);

FIFO* FIFOInit();

void FIFOPut(FIFO *pFIFO, int number);

int FIFOGet(FIFO *pFIFO);

void init_vector(int**vector, int size);

void BFS(int initial, node*list, int **parent, int size);
