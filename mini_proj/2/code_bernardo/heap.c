#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/* to remove comments, just delete or comment the next line */
#define DEMO

int max(int i, int n){
	if(i>n){
		return i;
	}else{
		return n;
	}
	return -1;
}

int maxNum(int a, int b){
  return (a < b);
}

/* A heap is represented by a structure: */
struct _heap {  
  int n_elements;               /* # elements in heap */
  int size;                     /* max size of the heap. */
  int *heapdata;               /* An array of ints. */
};

void FixDown(Heap * h, int k, int ** node_distance, int **node_identifiers)
{
  int j;
  int t;
  
  int colum;
  int colum_;
  int i;
  
  

  while ((2 * k + 1) < h->n_elements) {
    j = 2 * k + 1;
    if (((j + 1) < h->n_elements)){
		for(i=0; (h->heapdata[j])!=(*node_identifiers)[i]; i++)colum=i;
		for(i=0; (h->heapdata[j+1])!=(*node_identifiers)[i]; i++)colum_=i;
		if((maxNum((*node_distance)[colum], (*node_distance)[colum_]))){
			 j++;
		}
    }
    for(i=0; (h->heapdata[k])!=(*node_identifiers)[i]; i++)colum=i;
	for(i=0; (h->heapdata[j])!=(*node_identifiers)[i]; i++)colum_=i;
    if (! maxNum((*node_distance)[colum], (*node_distance)[colum_])) {
      /* Elements are in correct order. */

#ifdef DEMO
      /* --------------------------------------------------- */

#endif
      /*---------------------------------------------------------*/
      break;
    }
#ifdef DEMO

#endif
    /*---------------------------------------------------------*/

    /* the 2 elements are not correctly sorted, it is
       necessary to exchange them */
    t = (h->heapdata)[k];
    (h->heapdata)[k] = (h->heapdata)[j];
    (h->heapdata)[j] = t;
    k = j;

#ifdef DEMO
    /* --------------------------------------------------- */

#endif
    /*---------------------------------------------------------*/
  }

  return;
}

Heap *NewHeap(int size){
  Heap *h;

  h = (Heap *) malloc(sizeof(Heap));
  if (h == ((Heap *) NULL)) {
    fprintf(stderr, "Error in malloc of heap\n");
    exit(1);
  }

  h->n_elements = 0;
  h->size = size;
  h->heapdata = (int *) malloc(size * sizeof(int));
  if (h->heapdata == ((int *) NULL)) {
    fprintf(stderr, "Error in malloc of heap data\n");
    exit(1);
  }

  return (h);
}

void FreeHeap(Heap *h)
{
    free(h->heapdata);
    free(h);

   return;
}

void Direct_Insert(Heap * h, int element)
{
  if (h->n_elements == h->size) {
    return;
  }
  h->heapdata[h->n_elements] = element;

  h->n_elements++;


  return;
}

int RemoveMax(Heap * h, int ** node_distance, int **node_identifiers)
{
  int t;

  if (h->n_elements > 0) {
    t = (h->heapdata)[0];
    (h->heapdata)[0] = (h->heapdata)[h->n_elements - 1];
    (h->heapdata)[h->n_elements - 1] = t;
    h->n_elements--;
    FixDown(h, 0, &(*node_distance), &(*node_identifiers));
    return t;
  }
 return -1;
}

void Heapify(Heap * h, int **node_distance, int **node_identifiers)
{
	int i;
	for(i=h->n_elements-1; i>=0; i-=2){
		FixDown(h, (i-1)/2, &(*node_distance), &(*node_identifiers));
	}

    return;
}




int HeapEmpty(Heap*h){
	int b=0;
	if(h->n_elements==0)b=1;
	return b;
}



