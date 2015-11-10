
/******************************************************************************
 *
 * File Name: heap.h
 *	      (c) 2010 AED
 * Author:    AED team
 * Revision:  v2.3 ACR
 * NAME
 *     heap.h - prototypes
 *
 * SYNOPSIS
 *     #include <stdlib.h>
 *     #include <stdio.h>
 *     #include <string.h>
 *
 * DESCRIPTION
 *
 * DIAGNOSTICS
 *
 *****************************************************************************/



typedef struct _heap Heap;

int HeapEmpty(Heap*h);

Heap *NewHeap(int size);

/*void FreeHeap(Heap * h);*/

void Insert(Heap ** h, int element, int*node_distance);

void FixUp(Heap ** h, int k, int *node_distance);

int RemoveMax(Heap ** h, int *node_distance);

int PrintHeap(Heap * h);

void FixDown(Heap ** h, int k, int*node_distance);

/*void CleanHeap(Heap * h);*/


void Heapify(Heap ** h, int*node_distance);
