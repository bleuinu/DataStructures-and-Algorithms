#include <iostream> 
#include <climits> 
using namespace std;

void swap( int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

class MinHeap {
  private:
    int *harr;
    int capacity;
    int heap_size;

  public:
    MinHeap (int capacity);

    // to heapify a subtree with the root 
    void MinHeapify(int);

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    // returns the root at the min heap
    int getMin() { return harr[0]; }
    // extract the root which is the min
    int extractMin();

    // decrease key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);

    void insertKey(int k);

    void printMinHeap();
};

// Constructor
MinHeap::MinHeap(int cap)
{
  heap_size = 0;
  capacity = cap;
  harr = new int[cap];
}

// inserts a new key 
void MinHeap::insertKey(int k)
{
  if (heap_size == capacity)
  {
    cout << "\nOverflow: Could not insertKey\n";
    return;
  }

  // first insert the new key at the end 
  int i = heap_size; // i = 1
  ++heap_size;        // 2
  harr[i] = k;      // harr[1] = 15

  // fix the min heap 
  while (i != 0 && harr[i] < harr[parent(i)])
  {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

// decreases value of key at index 'i' to new_val 
// assumed that new_val is smaller than harr[i]
void MinHeap::decreaseKey(int i, int new_val) 
{
  harr[i] = new_val;
  // only conisdering moving up since we're assuming that new_val < harr[i]
  while (i != 0 && harr[i] < harr[parent(i)])
  {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

// remove the root 
int MinHeap::extractMin() 
{
  if (heap_size <= 0) return INT_MAX;
  if (heap_size == 1) 
  {
    --heap_size; 
    return harr[0];
  }

  // store the min value and remove it from heap 
  int root = harr[0];
  harr[0] = harr[heap_size-1]; // replace it with the last node 
  --heap_size; 
  MinHeapify(0);

  return root;
}

// deletes key at index.
void MinHeap::deleteKey(int i)
{
  decreaseKey(i, INT_MIN); // this brings the value to the root 
  extractMin();
}

void MinHeap::MinHeapify(int i) 
{
  int l = left(i);
  int r = right(i);
  int smallest = i; // parent which is the smallest in min heap

  if (l <  heap_size && harr[i] < harr[i])
    smallest = l; 
  if (r < heap_size && harr[r] < harr[smallest])
    smallest = r; 
  if (smallest != i) 
  {
    swap(&harr[i], &harr[smallest]);
    MinHeapify(smallest);
  }
}

void MinHeap::printMinHeap() 
{
  for (int i=0; i<heap_size; ++i)
  {
    cout << harr[i] << ' ';
  }
  cout << endl;
}

int main()
{
  MinHeap h(10);
  h.insertKey(10);
  h.insertKey(15);
  h.insertKey(30);
  h.insertKey(40);
  h.insertKey(50);
  h.insertKey(100);
  h.insertKey(40);
  cout << endl;
  h.printMinHeap();
  cout << endl;

  cout << h.extractMin() << endl;
  h.printMinHeap();

  h.decreaseKey(3, 2);
  h.printMinHeap();
  return 0;
}
