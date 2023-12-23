#include<iostream>
#include<vector>
using namespace std;
class node
{
public :
    int data;
    class node *next;
     node(int x){
      data=x;
      next=NULL;
    }
};
class SeparateChaining
{
public :
    void Insert(vector<node*>& , int);
    void Display(vector<node*>,int);
    void Searching(vector<node*>,int);
    void Delete(vector<node*>&,int);
};
void SeparateChaining::Delete(vector<node*>&HTable,int tsize){
       int x;
       cout<<"Enter the element to delete : ";
       cin>>x;
       int key = x%tsize;
       while(HTable[key]!=NULL){
         if(HTable[key]->next->data==x){
            node * temp=HTable[key]->next;
            HTable[key]->next=temp->next;
            temp->next=NULL;
            delete temp;
            cout<<"element is deleted"<<endl;
            return;
         }
         else{
            HTable[key]=HTable[key]->next;
         }

       }
       cout<<"Element is not found"<<endl;
}


void SeparateChaining::Searching(vector<node*>HTable,int tsize){
       int x;
       cout<<"Enter the element to search : ";
       cin>>x;
       int key = x%tsize;
       while(HTable[key]!=NULL){
         if(HTable[key]->data==x){
            cout<<"Element is found at index "<<key<<endl;
            return;
         }
         else{
            HTable[key]=HTable[key]->next;
         }

       }
       cout<<"Element is not found"<<endl;
}
void insertAtEnd(node* &Htable,node *newnode){
     node* temp=Htable;
     while(temp->next!=NULL){
        temp=temp->next;
     }
    temp->next=newnode;

}
void SeparateChaining::Insert(vector<node*> &HTable,int tsize){
    int x;
    cout<<"enter a value into hash table : ";
    cin>>x;
    node* newnode = new node(x);

    if(HTable[x%tsize]==NULL){
          HTable[x%tsize]=newnode;

    }
    else
        insertAtEnd(HTable[x%tsize],newnode);
}
void Inview(node* n){

     while(n!=NULL){
        cout<<n->data<<" -> ";
        n=n->next;
     }
     cout<<"\b\b\b\b    "<<endl;
}
void SeparateChaining::Display(vector<node*>HTable,int tsize){
  cout<<"\tINDEX\t|\tVALUE\t"<<endl;
   for(int i=0;i<tsize;i++)
   {
       if(HTable[i]==NULL)
       cout<<"\t"<<i<<"\t|\t"<<HTable[i]<<"\t";
       else
        cout<<"\t"<<i<<"\t|\t";
        Inview(HTable[i]);
   }

}
int main(){
   SeparateChaining h;
   int tsize;
   cout<<"enter the size of the Hash table"<<endl;
   cin>>tsize;
   vector<node *>HTable(tsize,NULL);
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



