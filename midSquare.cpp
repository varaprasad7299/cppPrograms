#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void Insert(vector<int> &HTable,int tsize){
    int x;
    cout<<"enter a value into hash table : ";
    cin>>x;
    int s = pow(x,2);
    int nod = 1+ (int)log10(s);
    s=s/(int)pow(10,nod/2);
    HTable[s%10]=x;


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

