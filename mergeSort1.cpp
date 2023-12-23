#include<iostream>
#include<fstream>
using namespace std;
void merge( int a[],int lb,int mid,int ub,int l,ofstream& out)
{
    static int c=0;
    int b[ub+1];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
           b[k]=a[i];
           i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
        a[k]=b[k];
     out<<"for iteration "<<++c<<endl;
    for(int i=0;i<l;i++)
        out<<a[i]<<" ";
    out<<endl;

}
 void mergeSort( int a[],int low,int high,int l,ofstream& out)
{

     if(low<high)
     {
         int mid=(low+high)/2;
         mergeSort(a,low,mid,l,out);
         mergeSort(a,mid+1,high,l,out);
         merge(a,low,mid,high,l,out);
     }
}
int main(){

   int i,n,x;
   ifstream in;
   in.open("input.txt");
   ofstream out;
   out.open("output.txt");
   out<<"MERGE SORT"<<endl<<endl;
   in>>n;
   int arr[n];
   i=0;
   while(in>>x){
    arr[i++]=x;
   }
    out<<"elements in the array before sorting"<<endl;
    for(i=0;i<n;i++)
        out<<arr[i]<<" ";
    out<<endl;
    mergeSort(arr,0,n-1,n,out);
    out<<"elements in the array after sorting"<<endl;
   for(i=0;i<n;i++)
        out<<arr[i]<<" ";
    in.close();
    out.close();
  return 0;
}

