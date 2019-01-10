#include<iostream>
#include < stdio.h>
#include < time.h>
#include<algorithm>
#include <stack>
#include < stdio.h>
using namespace std;
 
template<class T>
class Array
{
private:
int size ;
T * A;    
 
public:
Array ();
Array (int sz);
Array ( const Array &x );   
~Array();                            
void Randomize ();
int get_size() {return size;}
template < class U >
friend ostream & operator << (ostream & out , const Array<U> &ar ) ;
T &operator[](int index);
 
void sort(void(*sorting)(T*, int)){
  sorting(A, size);
 }
 
    };
 
 
 
 template <class T>
 T & Array<T> ::  operator [] (int indx)
    { 
        return A[indx];
        }
 
 
template < class T>
Array <T> :: Array ()
{ size=0 ; A=NULL;}
 
template < class T >
Array <T> :: Array( int sz)
 { size=sz; A=new T[sz]; }
 
template < class T >
Array <T> :: Array ( const Array & x)
 { for ( int i=0 ; i<size ; ++i)
    A[i]=x.A[i];}
 
template < class T >
Array < T > :: ~Array ()
{
    A=NULL;
    }
 
template < class U >
ostream &operator << ( ostream & out , const Array < U > &ar) 
{
    int l=ar.size;
    for ( int i=0 ; i<l ; ++i)
    {if ( i % 5 ==0 ) out<<"\n" ;
     out<<ar.A[i]<<"\t";}
    return out;
    }
 
 
template <>
void Array <long long int> :: Randomize()
{
    srand(time(NULL));
    for ( int i=0 ; i<size ; ++i )
        A[i]=(rand()<<17) + (rand()<<2) + rand()%4 ;
    }    
 
 
template <class T>
void Bubble_sort(T * A,  int size)
{
    long long int tem;
 
    for (  int i=0 ; i<size-1 ; ++i )
        for ( int j=0 ; j<size-i-1 ; ++j)
            if (A[j] > A[j+1])  { tem=A[j]; A[j]=A[j+1]; A[j+1]=tem;}
    }  
 
 
template <class T>
void XBubble_sort( T * A ,  int size)
{
    long long int tem;
    bool swap= true;
 
    for ( int i=0 ; i<size-1 ; ++i )
    {   
        swap=false;
        for ( int j=0 ; j<size-i-1 ; ++j)
            if (A[j] > A[j+1])  { tem=A[j]; A[j]=A[j+1]; A[j+1]=tem; swap=true;}
        if (!swap) return ;
    }
 
    }
 
template <class T>
 void heapify( T * A , int start , int sz)
 {
 
     int l=2*start+1;
     int r=2*start+2;
 
     if (l >= sz) return ; //No Child
     if (r >= sz)  {if (A[l]>A[start]) swap(A[l],A[start]); return ;}// No right Child , Only left Child
 
     if ((A[start] > A[l]) && (A[start] > A[r] )) return ; //already heapify
 
     if (A[l] > A[start]) { swap(A[l],A[start]); heapify(A,l,sz);}
     if (A[r] > A[start]) { swap(A[r],A[start]); heapify(A,r,sz);}
 
     }
 
 /*Complexity (n/2)log(n) + nlog(n)*/
 template <class T>
 void Heap_sort ( T * A , int sz)
 {
     /*Build The heap*/
     for (int i=sz/2 -1 ; i>=0 ; --i)
     heapify(A,i,sz);
 
         for (int i=sz-1; i>=0; i--)
    {
        // Move current root to end
        swap(A[0], A[i]);
 
        // call max heapify on the reduced heap
        heapify(A, 0, i);
    }
 
     }
 
 
/*
 How does the quick sort works ?
 
   This function takes the middle element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot
 */
 
 
 template <class T>
 int Partition(T * A , int left , int right)
 {
     int m=(left+right)/2;
     swap(A[left],A[m]); // put Pivot at the left 
     int pivot=A[left]; // get the pivot value
 
     int lo=left+1 , hi=right; //give my two pointers the correct values
 
     while ( lo <= hi )
     {
         while (A[hi]  > pivot ) hi--;
         while ( lo<=hi && A[lo] <= pivot ) lo++;
 
         if ( lo <= hi ) swap(A[lo],A[hi]) , lo++ , hi--;
 
         }
 
     swap(A[left]  , A[hi]); // put PIVOT on its right location
     return hi;
 
     }
 
 template <class T>
void quick(T *  A , int left , int right)
{
    int pivot ;
 
    if (left < right)
    {
        pivot=Partition(A,left,right);
        quick(A,left,pivot-1);
        quick(A,pivot+1,right);
 
        }
 
    }
 
template <class T>
void quick_stack(T * A , int sz)
{
    int low=0;
    int heigh=sz-1;
    int pivot ;
 
    stack < int > s ;
    s.push(0); s.push(-1);
 
    while (!s.empty())
    {
        while (low < heigh)
        {
 
            pivot=Partition(A,low,heigh);
            s.push(pivot); s.push(heigh);
            heigh=pivot-1;
 
 
            }
 
        s.pop(); s.pop();
 
        }   
 
 
    }
 
template <class T>
void Quick_sort (T *  A , int sz)
{
    quick(A,0,sz-1);
 
    }
 
 template <class T>
void merge(T * a, int first,int last){
 
    if (first>=last) return;
    int mid=(first+last)/2;
    merge(a,first,mid);
    merge(a,mid+1,last);
    int i=first;
    int j=mid+1;
    int k=0;
    long* temp=new long[last-first+1];
    while (i<=mid && j<=last){
    while (i<=mid && a[i]<=a[j]){temp[k++]=a[i++];}
    while (j<=last && a[i]>a[j]){temp[k++]=a[j++];}
    }
 
    while (i>mid && j<=last) temp[k++]=a[j++];
    while (j>last && i<=mid) temp[k++]=a[i++];
 
    for (i=first;i<=last;i++) a[i]=temp[i-first];
    delete temp;
    }
 
template <class T>
    void mergeSort(T *  a,int size){
    merge(a,0,size-1);
        }
 
int main()
{
    freopen("ouput.txt","w",stdout);
 
  const int sz=1e5;
   puts("\n");
   printf("Study the time complexity for Bubble sort \n\n");
   for (int i=10 ; i<=sz ; i*=10)
   {
    Array < long long int > A(i);
    A.Randomize();
    clock_t Start = clock();
    A.sort(&Bubble_sort);
    printf(" Array size = %d \n Time taken: %fs\n", i ,(double)(clock() - Start) /CLOCKS_PER_SEC);
    puts("\n");   
    }   
 

   puts("\n");
   printf("Study the time complexity for Heap sort \n\n");
   for (int i=10 ; i<=sz ; i*=10)
   {
    Array < long long int > A(i);
    A.Randomize();
    clock_t Start = clock();
    A.sort(&Heap_sort);
    printf(" Array size = %d \n Time taken: %fs\n", i ,(double)(clock() - Start) /CLOCKS_PER_SEC);
    puts("\n");   
    }   
 
 
 
   puts("\n");
   printf("Study the time complexity for Quick sort \n\n");
   for (int i=10 ; i<=sz ; i*=10)
   {
    Array < long long int > A(i);
    A.Randomize();
    clock_t Start = clock();
    A.sort(&Quick_sort);
    printf(" Array size = %d \n Time taken: %fs\n", i ,(double)(clock() - Start) /CLOCKS_PER_SEC);
    puts("\n");   
    }   
 
 
return 0; }

