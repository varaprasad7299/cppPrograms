#include<iostream>
#include<fstream>
using namespace std;
int binary(int arr[],int i,int j,int ele)
{
    if(i<j)
    {
        int mid=(i+j)/2;
        if(ele==arr[mid])
            return mid;
        else if(ele<arr[mid])
                return binary(arr,i,mid-1,ele);
        else if(ele>arr[mid])
                return binary(arr,mid+1,j,ele);

    }
    else
        return -1;
}
int main()
{
    int i,n,x,ele,r;

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
   out<<"elements in the array"<<endl;
   for(int i=0;i<n;i++)
    out<<arr[i]<<" ";
   out<<endl;
    out<<"enter element to be search: ";
    cin>>ele;
    out<<ele<<endl;
    r=binary(arr,0,n,ele);
    if(r==-1)
        out<<"element is not found in the array";
    else
        out<<"element is present at index is "<<r;

    return 0;
}
