int LessNum(int a, int b);

typedef struct _heap Heap;

Heap *NewHeap(int tamanho);

void FreeHeap(Heap * h);

void FixUp(Heap * h, int k);

void FixDown(Heap * h, int k);

void Direct_Insert(Heap * h, int element);

int RemoveMax(Heap * h, int**node_distance);

void Heapify(Heap * h);

int HeapEmpty(Heap*h);

int maxNum(int a, int b);

int max(int i, int n);
