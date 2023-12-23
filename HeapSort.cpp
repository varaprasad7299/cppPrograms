#include<iostream>
#include<fstream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    while(l<n&&a[l]>a[largest])
    {
        largest=l;
    }
    while(r<n&&a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}
void heap_sort(int a[],int n,ofstream& out)
{
    static int c=0;
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    out<<"elements in array after the heapify() :"<<endl;
    for(int i=0;i<n;i++)
        out<<a[i]<<" ";
    out<<endl;
    for(int i=n-1;i>=0;i--)
    {
        swap(&a[i],&a[0]);
        heapify(a,i,0);
        out<<"for iteration "<<++c<<" :"<<endl;
        for(int i=0;i<n;i++)
        out<<a[i]<<" ";
        out<<endl;
    }
}
int main()
{
    int i,n,x;

   ifstream in;
   in.open("input.txt");
   ofstream out;
   out.open("output.txt");
   out<<"HEAP SORT"<<endl<<endl;
   in>>n;
   int arr[n];
   i=0;
   while(in>>x){
    arr[i++]=x;
   }
    out<<"elements in the array before sorting :"<<endl;
    for(i=0;i<n;i++)
        out<<arr[i]<<" ";
    out<<endl<<endl;
    heap_sort(arr,n,out);
    out<<endl;
    out<<"elements in the array after sorting :"<<endl;
   for(i=0;i<n;i++)
        out<<arr[i]<<" ";
    in.close();

    return 0;
}
