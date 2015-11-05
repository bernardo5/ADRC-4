int LessNum(int a, int b);

typedef struct _heap Heap;

Heap *NewHeap(int tamanho);

void FreeHeap(Heap * h);

void FixUp(Heap * h, int k);

void FixDown(Heap * h, int k, int **node_distance, int **node_identifiers);

void Direct_Insert(Heap * h, int element);

int RemoveMax(Heap * h, int**node_distance, int **node_identifiers);

void Heapify(Heap * h, int**node_distance, int **node_identifiers);

int HeapEmpty(Heap*h);

int maxNum(int a, int b);

int max(int i, int n);
