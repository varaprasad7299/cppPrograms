#include<iostream>
#include<vector>
using namespace std;
class DoubleHashing
{
public :
    void Insert(vector<int>& , int);
    void Display(vector<int>,int);
    void Searching(vector<int>,int);
    void Delete(vector<int>&,int);
};
void DoubleHashing::Delete(vector<int>&HTable,int tsize){
    int x;
       cout<<"Enter the element to Delete : ";
       cin>>x;
       if(HTable[x%tsize]==x){
            HTable[x%tsize]=0;
            cout<<"element is deleted"<<endl;
            }

       else
       {   int i;
           int hkey= 7-(x%7);
           for( i=1;i<tsize;i++){
            int key = ((x%tsize)+(i*hkey))%tsize;
            if(HTable[key]==x){
               HTable[key]=0;
               cout<<"element is deleted"<<endl;
                 break;
            }
           }
           if(i>=tsize){
            cout<<"Element is not found"<<endl;
           }
       }
}
void DoubleHashing::Searching(vector<int>HTable,int tsize){
      int x;
       cout<<"Enter the element to search : ";
       cin>>x;
       if(HTable[x%tsize]==x)
        cout<<"The element is found at index "<<x%tsize<<endl;
       else
       {   int i;
           int hkey= 7-(x%7);
           for( i=0;i<tsize;i++){
            int key = ((x%tsize)+(i*hkey))%tsize;
            if(HTable[key]==x){
                 cout<<"The element is found at index "<<key<<endl;
                 break;
            }
           }
           if(i>=tsize){
            cout<<"Element is not found"<<endl;
           }
       }
}

void DoubleHashing::Insert(vector<int> &HTable,int tsize){
    int x;
    cout<<"enter a value into hash table : ";
    cin>>x;
    if(HTable[x%tsize]==0)
       HTable[x%tsize]=x;
    else{
        int i;
        int hkey= 7-(x%7);
        for( i=0;i<tsize;i++){
            int key = ((x%tsize)+(i*hkey))%tsize;
            if(HTable[key]==0){
                HTable[key]=x;
                break;
            }
        }
        if(i>tsize)
            cout<<"Cannot insert the element"<<endl;
    }
}
void DoubleHashing::Display(vector<int>HTable,int tsize){
   cout<<"\tINDEX\t|\tVALUE\t"<<endl;
   for(int i=0;i<tsize;i++)
   {
       cout<<"\t"<<i<<"\t|\t"<<HTable[i]<<"\t"<<endl;
   }

}
int main(){
   DoubleHashing h;
   int tsize;
   cout<<"enter the size of the Hash table"<<endl;
   cin>>tsize;
   vector<int>HTable(tsize,0);
     int choice =1;
   while(choice != 5){
   cout<<"1.Insert()\n2.Delete()\n3.Search()\n4.Display()\n5.exit."<<endl;
   cout<<"enter the choice : ";
   cin>>choice;
   if(choice ==1)
     h.Insert(HTable,tsize);
           if(choice==2)
                h.Delete(HTable,tsize);
    if(choice ==3)
        h.Searching(HTable,tsize);
    if(choice ==4)
        h.Display(HTable,tsize);
}

   return 0;
}



