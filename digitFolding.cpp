#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void Insert(vector<int> &HTable,int tsize){
    int x,a,b,c;
    cout<<"enter a value into hash table : ";
    cin>>x;
    int num1=x;
    while(num1 > tsize){
      int nod = (int) log10(num1)+1;
      if(nod<3){
         nod = 3;
      }
      a = num1 % (int)pow(10,nod/3);
      b = num1/(int)pow(10,nod/3);
      c = b/(int)pow(10,nod/3);
      b = b % (int)pow(10,nod/3);
      num1=a+b+c;
    }
    HTable[num1]=x;
}
int main(){
   int tsize;
   cout<<"enter the size of the Hash table"<<endl;
   cin>>tsize;
   vector<int>HTable(tsize,0);
   for(int i : HTable)
       Insert(HTable,tsize);
   cout<<"\tINDEX\t|\tVALUE\t"<<endl;
   for(int i=0;i<tsize;i++)
   {
       cout<<"\t"<<i<<"\t|\t"<<HTable[i]<<"\t"<<endl;
   }
   return 0;
}


