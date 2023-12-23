#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
int partition(int arr[],int low,int high,int l,ofstream& out)
{
    int pivot=arr[low];
    int i,j,k;
    static int c=0;
    i=low;
    j=high;
    while(i<j)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    arr[low]=arr[j];
    arr[j]=pivot;
    out<<"for iteration "<<++c<<" :"<<endl;
    for(int i=0;i<l;i++)
        out<<arr[i]<<" ";
    out<<endl;
    return j;
}
void quick(int arr[],int p,int q,int l,ofstream& out)
{

    if(p<q)
    {
        int j=partition(arr,p,q,l,out);
        quick(arr,p,j-1,l,out);
        quick(arr,j+1,q,l,out);
    }
}
int main()
{
    int i,n,x;

   ifstream in;
   in.open("input.txt");
   ofstream out;
   out.open("output.txt");
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
    quick(arr,0,n-1,n,out);
    out<<endl;
    out<<"elements in the array after sorting :"<<endl;
   for(i=0;i<n;i++)
        out<<arr[i]<<" ";
    in.close();

   /* for(int i=0;i<n;i++){
        out<<arr[i]<<endl;
    }*/
    out.close();
}
