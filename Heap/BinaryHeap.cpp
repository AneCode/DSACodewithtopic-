#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
class MaxHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
   public:
   MaxHeap(int capacity);
    int Size(){ return heap_size;}
    // to heapify a subtree with the root at given index
    void MaxHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
  
    // to extract the root which is the maximum element
    int extractMax();
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
  
    // Returns the minimum key (key at root) from min heap
    int getMax() { return harr[0]; }
  
    // Deletes a key stored at index i
    void deleteKey(int i);
  
    // Inserts a new key 'k'
    void insertKey(int k);
    void print(){
        for(int i=0;i<heap_size;i++){
            cout<<harr[i]<<"--";
        }
    }
   void ReSizeHeap();
   void perculatedown(int i);
   void BuildHeap(int* arr,int n);
};
MaxHeap::MaxHeap(int capacity){
    harr=new int[capacity];
    capacity=capacity;
    heap_size=0;
}
void MaxHeap::perculatedown(int i){
   int max=i;
    int l=left(i);
    int r=right(i);
    if(l<heap_size && harr[l]>harr[i])
     max=l;
     if(r<heap_size && harr[r]>harr[max])
     max=r;
   
     if(max!=i){
         swap(&harr[i],&harr[max]);
        perculatedown(max);
     }

}
void MaxHeap::BuildHeap(int*arr,int n){
   capacity=n;
   for(int i=0;i<n;i++){
       harr[i]=arr[i];
   }
   heap_size=n;
   int j=heap_size-1;
   for(int i=parent(j);i>=0;i--){
       perculatedown(i);
   }
}
void MaxHeap::insertKey(int k){
    if(heap_size==capacity)
      {
        ReSizeHeap();
      } 
     heap_size++;
     int i=heap_size-1;
     harr[i]=k;
     if(i && harr[i]> harr[parent(i)]){
         while(harr[i]>harr[parent(i)]){
             swap(&harr[i],&harr[parent(i)]);
             i=parent(i);
         }
     }

}
void MaxHeap::decreaseKey(int i,int key){
    harr[i]=key;
    if(i && harr[i]> harr[parent(i)]){
         while(harr[i]>harr[parent(i)]){
             swap(&harr[i],&harr[parent(i)]);
             i=parent(i);
         }
     }
}
void MaxHeap::ReSizeHeap(){
    harr=(int*)realloc(harr,capacity*2);
    capacity*=2;
}
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);
  
    return root;
}
void MaxHeap::deleteKey(int i)
{
    // decreaseKey(i,harr[0]+1);
      harr[i]=harr[0]+1;
    if(i && harr[i]> harr[parent(i)]){
         while(harr[i]>harr[parent(i)]){
             swap(&harr[i],&harr[parent(i)]);
             i=parent(i);
         }
     }
    extractMax();
}
 void MaxHeap::MaxHeapify(int i){

    int max=i;
    int l=left(i);
    int r=right(i);
    if(l<heap_size && harr[l]>harr[i])
     max=l;
     if(r<heap_size && harr[r]>harr[max])
     max=r;
   
     if(max!=i){
         swap(&harr[i],&harr[max]);
        MaxHeapify(max);
     }
 }
 class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
    int Size(){ return heap_size;}
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
  
    // to extract the root which is the minimum element
    int extractMin();
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
  
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
  
    // Deletes a key stored at index i
    void deleteKey(int i);
  
    // Inserts a new key 'k'
    void insertKey(int k);
     void ReSizeHeap();
   void perculatedown(int i);
   void BuildHeap(int* arr,int n);
};
  
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
void MinHeap::perculatedown(int i){
   int max=i;
    int l=left(i);
    int r=right(i);
    if(l<heap_size && harr[l]>harr[i])
     max=l;
     if(r<heap_size && harr[r]>harr[max])
     max=r;
   
     if(max!=i){
         swap(&harr[i],&harr[max]);
        perculatedown(max);
     }

}
void MinHeap::BuildHeap(int*arr,int n){
   capacity=n;
   for(int i=0;i<n;i++){
       harr[i]=arr[i];
   }
   int j=heap_size-1;
   for(int i=parent(j);i>=0;i--){
       perculatedown(i);
   }
}
void MinHeap::ReSizeHeap(){
    harr=(int*)realloc(harr,capacity*2);
    capacity*=2;
}
  
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
  
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
  
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}
  
  
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
  
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void HeapSort(int *arr,int n ){
MaxHeap h(5);
h.BuildHeap(arr,n);
while(h.Size()>0){
  cout<<h.extractMax()<<endl;
 }
}
int main(){
//  MaxHeap h(5);
    // h.insertKey(3);
    // h.insertKey(2);
    // // h.deleteKey(1);
    // h.insertKey(15);
    // h.insertKey(5);
    // h.insertKey(4);
    // h.insertKey(45);
    // // h.print();
    // // cout << h.extractMax() << " \n";
    // // // h.print();
    // // cout << h.getMax() << " ";
    // // h.print();
    // // h.decreaseKey(2, 1);
    // // cout<<"\n";
    // // h.print();
    // // cout << h.getMax();
    // h.print();
    // cout<<"\n";
    // h.deleteKey(2);
    // h.print();
    int * arr=new int[5];
    for(int i=0 ;i<5;i++)
    cin>>arr[i];
    HeapSort(arr,5);
    return 0;
 }
