#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void Insert(vector<int> &HTable,int tsize){
    int x,a,b,c;
    cout<<"enter a value into hash table : ";
    cin>>x;
    float intpart;
    int key = floor((tsize*(modf(x*0.123,&intpart))));
    HTable[key]=x;

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



