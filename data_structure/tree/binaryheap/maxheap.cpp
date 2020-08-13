#include <iostream> 
#include <climits>
using namespace std;

static void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

class MaxHeap
{
  private:
    int *harr;      // heap array
    int heap_size;  // number of nodes in the heap 
    int capacity;   // max size of the heap 

  public:
    MaxHeap(int capacity);

    // heapify the subtree with the root at given index
    void MaxHeapify(int);

    static int parent(int i) { return (i-1)/2; }
    static int left(int i) { return (2*i) + 1; }
    static int right(int i) { return (2*i) + 2; }

    int getMax() const { return harr[0]; }
    int extractMax();

    void increaseKey(int i, int new_val);

    void deleteKey(int i);
    void insertKey(int k);

    void printHeap();
};

MaxHeap::MaxHeap(int cap) 
{
  harr = new int[cap];
  heap_size = 0;
  capacity = cap;
}

void MaxHeap::insertKey(int k)
{
  if (heap_size == capacity)
  {
    cout << "\nOverflow: could not insert key.\n";
    return ;
  }

  int i = heap_size;
  ++heap_size;
  harr[i] = k;

  while (i != 0 && harr[i] > harr[parent(i)])
  {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

void MaxHeap::increaseKey(int i, int new_val)
{
  harr[i] = new_val;
  while (i != 0 && harr[i] > harr[parent(i)])
  {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

void MaxHeap::deleteKey(int i)
{
  increaseKey(i, INT_MAX);
  extractMax();
}

int MaxHeap::extractMax()
{
  if (heap_size <= 0) return INT_MIN;
  if (heap_size == 1) 
  {
    --heap_size;
    return harr[0];
  }

  int root = harr[0];
  harr[0] = harr[heap_size-1];
  --heap_size;
  MaxHeapify(0);

  return root;
}

void MaxHeap::MaxHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (l < heap_size && harr[l] > harr[i])
    largest = l;
  if (r < heap_size && harr[r] > harr[largest])
    largest = r;
  if (largest != i)
  {
    swap(&harr[i], &harr[largest]); 
    MaxHeapify(largest);
  }
}

void MaxHeap::printHeap()
{
  for (int i=0; i<heap_size; ++i)
  {
    cout << harr[i] << ' ';
  }
  cout << endl;
}

int main()
{
  MaxHeap h(10);
  h.insertKey(1);
  h.insertKey(5);
  h.insertKey(2);
  h.insertKey(7);
  h.insertKey(3);
  h.insertKey(8);
  h.insertKey(4);
  h.insertKey(9);
  h.insertKey(6);
  h.printHeap();

  h.extractMax();
  h.printHeap();

  h.deleteKey(5);
  h.printHeap();
  return 0;
}
