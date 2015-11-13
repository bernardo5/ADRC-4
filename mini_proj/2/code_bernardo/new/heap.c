/******************************************************************************
 *
 * File Name: heap.c
 *	      (c) 2010 AED
 * Author:    AED team
 * Revision:  v2.3 ACR
 *
 * NAME
 *     Heap11 - Heap operations
 *
 * SYNOPSIS
 *     #include <stdlib.h>
 *     #include <stdio.h>
 *     #include <malloc.h>
 *
 * DESCRIPTION
 *		implements tree auxiliary functions
 * DIAGNOSTICS tested
 *
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/* to remove comments, just delete or comment the next line */
#define DEMO

/* A heap is represented by a structure: */
struct _heap {
  int n_elements;               /* # elements in heap */
  int size;                     /* max size of the heap. */
  int *heapdata;               /* An array of Items. */
};

int HeapEmpty(Heap*h){
	if(h->n_elements!=0) return 1;
	return 0;
}


/******************************************************************************
 * FixUp()
 *
 * Arguments: h - pointer to heap structure
 *            k - index of element to fixup
 * Returns:
 * Side-Effects: none
 *
 * Description: Performs fixup from index
 *
 *****************************************************************************/

void FixUp(Heap * h, int k, int *node_distance, int**heap_place, int*node_hops)
{
  int t;
  while ((k > 0) && (node_distance[(((h)->heapdata)[(k - 1) / 2])-1]<=node_distance[(((h)->heapdata)[k])-1])) {
#ifdef DEMO
    /* --------------------------------------------------- */
   /* printf("FixUp: heap[%d]: %d is smaller than offspring heap[%d]: %d\n",
           (k - 1) / 2, *((int *) (h->heapdata)[(k - 1) / 2]),
           k, *((int *) (h->heapdata)[k]));
    printf("\t=> exchange\n");*/
#endif
    /*---------------------------------------------------------*/
    if(node_distance[(((h)->heapdata)[(k - 1) / 2])-1]==node_distance[(((h)->heapdata)[k])-1]){ /*same route*/
		if(node_hops[(((h)->heapdata)[(k - 1) / 2])-1]>node_hops[(((h)->heapdata)[k])-1]){ /*only changes to put first the one with less hops*/
			t = ((h)->heapdata)[k];
			((h)->heapdata)[k] = ((h)->heapdata)[(k - 1) / 2];
			((h)->heapdata)[(k - 1) / 2] = t;
			
			(*heap_place)[(((h)->heapdata)[(k - 1) / 2])-1]=(k - 1) / 2;
			(*heap_place)[(((h)->heapdata)[k])-1]=k;
		}
	}else{
		t = ((h)->heapdata)[k];
		((h)->heapdata)[k] = ((h)->heapdata)[(k - 1) / 2];
		((h)->heapdata)[(k - 1) / 2] = t;
		
		(*heap_place)[(((h)->heapdata)[(k - 1) / 2])-1]=(k - 1) / 2;
		(*heap_place)[(((h)->heapdata)[k])-1]=k;
	}
    

#ifdef DEMO
    /* --------------------------------------------------- */
    /*printf("\t=> \n");
    PrintHeap(h);*/
#endif
    /*---------------------------------------------------------*/
    k = (k - 1) / 2;
  }

  return;
}


/******************************************************************************
 * FixDown()
 *
 * Arguments: h - pointer to heap structure
 *            k - index of element to fixdown
 * Returns:
 * Side-Effects: none
 *
 * Description: performs fixdown from index
 *
 *****************************************************************************/

void FixDown(Heap * h, int k, int*node_distance, int**heap_place, int*node_hops)
{
  int j;
  int t;

  while ((2 * k + 1) < (h)->n_elements) {
    j = 2 * k + 1;
    if (((j + 1) < (h)->n_elements) &&
        (node_distance[((h)->heapdata[j])-1]<=node_distance[((h)->heapdata[j + 1])-1])){
      if(node_distance[((h)->heapdata[j])-1]==node_distance[((h)->heapdata[j + 1])-1]){
		  if(node_hops[((h)->heapdata[j])-1]>node_hops[((h)->heapdata[j + 1])-1]) j++;
	  }else{
		 j++; 
	  }
      
      
    }
    if (node_distance[((h)->heapdata[k])-1]>=node_distance[((h)->heapdata[j])-1]){
      /* Elements are in correct order. */

#ifdef DEMO
      /* --------------------------------------------------- */
     /* printf
          ("FixDown: Compare heap[%d]: %d with heap[%d]: %d => don't exchange\n",
           k, *((int *) h->heapdata[k]), j, *((int *) h->heapdata[j]));*/
#endif
      /*---------------------------------------------------------*/
      if(node_distance[((h)->heapdata[k])-1]==node_distance[((h)->heapdata[j])-1]){
		  if(node_hops[((h)->heapdata[k])-1]<node_hops[((h)->heapdata[j])-1]) break; /*correct order if hops are less in father side*/
	  }else{ /*diferent route types*/
		break;  
	  }
      
      
    }
#ifdef DEMO
    /* --------------------------------------------------- */
   /* printf("FixDown: heap[%d]: %d is smaller than offspring heap[%d]: %d\n",
           k, *((int *) (h->heapdata)[k]), j, *((int *) (h->heapdata)[j]));
    printf("\t=> exchange\n");*/
#endif
    /*---------------------------------------------------------*/

    /* the 2 elements are not correctly sorted, it is
       necessary to exchange them */
    t = ((h)->heapdata)[k];
    ((h)->heapdata)[k] = ((h)->heapdata)[j];
    ((h)->heapdata)[j] = t;
    
    (*heap_place)[(((h)->heapdata)[j])-1]=j;
    (*heap_place)[(((h)->heapdata)[k])-1]=k;
    
    k = j;

#ifdef DEMO
    /* --------------------------------------------------- */
   /* PrintHeap(h);*/
#endif
    /*---------------------------------------------------------*/
  }

  return;
}


/******************************************************************************
 * NewHeap()
 *
 * Arguments: size - heap size
 *            less - item comparison function
 * Returns: Heap
 * Side-Effects: none
 *
 * Description: allocates space for a new heap of specified size
 *
 *****************************************************************************/

Heap *NewHeap(int size)
{
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

/******************************************************************************
 * NewHeap()
 *
 * Arguments: size - heap size
 *            less - item comparison function
 * Returns: Heap
 * Side-Effects: none
 *
 * Description: allocates space for a new heap of specified size
 *
 *****************************************************************************/

/*void FreeHeap(Heap *h)
{
    free(h->heapdata);
    free(h);
    
   return;
}*/

/******************************************************************************
 * Insert()
 *
 * Arguments: h - pointer to heap
 *            element - pointer to new element
 * Returns: vopid
 * Side-Effects: none
 *
 * Description: add element at the end of heap and do fixup
 *
 *****************************************************************************/

void Insert(Heap * h, int element, int*node_distance, int**heap_place, int*node_hops)
{
  if ((h)->n_elements == (h)->size) {
    printf("Heap full (size = %d) !\n", (h)->size);
    return;
  }
  (h)->heapdata[(h)->n_elements] = element;

  (h)->n_elements++;
  (*heap_place)[element-1]=(h->n_elements)-1;
  FixUp(h, ((h)->n_elements) - 1, node_distance, &(*heap_place), node_hops);
//parentesis no 2 termo fix up
  return;
}

/******************************************************************************
 * Direct_Insert()
 *
 * Arguments: h - pointer to heap
 *            element - pointer to new element
 * Returns: vopid
 * Side-Effects: none
 *
 * Description: add element at the end of heap but does not perform fixup
 *
 *****************************************************************************/



/******************************************************************************
 * Modify()
 *
 * Arguments: h - pointer to heap
 *            index - index of element to modify
 *            newvalue - new element value
 * Returns: void
 * Side-Effects: none
 *
 * Description: compares new element with antecedent, if larger do a fixup
 *              otherwise do fixdown
 *
 *****************************************************************************/


/******************************************************************************
 * RemoveMax()
 *
 * Arguments: h - pointer to heap
 * Returns: Item
 * Side-Effects: none
 *
 * Description: exchange first and last element of heap, remove last element
 *              (max element) from heap and maintain heap order by performing
 *              a fixdown of the first element
 *
 *****************************************************************************/

int RemoveMax(Heap * h, int *node_distance, int**heap_place, int *node_hops)
{
  int t;

  if ((h)->n_elements > 0) {

    t = ((h)->heapdata)[0];
    ((h)->heapdata)[0] = ((h)->heapdata)[(h)->n_elements - 1];
    //((h)->heapdata)[(h)->n_elements - 1] = t;
    (*heap_place)[((h)->heapdata)[(h)->n_elements - 1]-1]=0;
    (*heap_place)[t-1]=-1;
    (h)->n_elements--;
    FixDown(h, 0, node_distance, &(*heap_place), node_hops);
	 //(*heap_place)[t-1]=-1;
  /*  for(i=0; i<(h)->n_elements; i++)printf("%d\t", ((h)->heapdata)[i]);
    printf("\n\n");*/
    return t;
  }

  return -1;
}

/******************************************************************************
 * CleanHeap()
 *
 * Arguments: Heap
 * Returns: none
 * Side-Effects: None
 *
 * Description: cleans an heap
 *
 *****************************************************************************/

/*void CleanHeap(Heap * h)
{
	int i;
	
	for(i=0; i<h->n_elements; i++){
		free(h->heapdata[i]);
	}
	h->n_elements=0;
    return;
}*/

/******************************************************************************
 * VerifyHeap()
 *
 * Arguments: Heap
 * Returns: int (1 if it is an heap; 0 otherwise)
 * Side-Effects: None
 *
 * Description: verifies if the argument satisfies the heap condition
 *
 *****************************************************************************/



/******************************************************************************
 * HeapSort()
 *
 * Arguments: Heap
 * Returns: void
 * Side-Effects: 
 *
 * Description: sorts an heap using the heapsort algorithm
 *
 *****************************************************************************/



/******************************************************************************
 * Heapify()
 *
 * Arguments: Heap
 * Returns: void
 * Side-Effects:
 *
 * Description: forces the argument to be an heap
 *
 *****************************************************************************/

/*void Heapify(Heap * h, int*node_distance)
{
	int i;
	for(i=(h)->n_elements-1; i>=0; i-=2){
		FixDown(h, (i-1)/2, node_distance);
	}

    return;
}*/
