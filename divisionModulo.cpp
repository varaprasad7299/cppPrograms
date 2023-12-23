#include<iostream>
#include<vector>
using namespace std;
void Insert(vector<int> &HTable,int tsize){
    int x;
    cout<<"enter a value into hash table : ";
    cin>>x;
    HTable[x%tsize]=x;

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

