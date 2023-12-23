#include<iostream>
#include<vector>
using namespace std;

class HashTable{
 public:
  vector<int> HTable;
  int size;
  int elementsNo;
  double loadFactor;
  HashTable(){
    size=10;
    elementsNo=0;
    loadFactor=0;
    HTable.resize(size);
  }
  void Insert();
  void Delete();
  void Show();
  void Searching();
  void rehashing();
  int hashkey(int);


};

void HashTable::Insert(){
     cout<<"enter a value : ";
     int x;
     cin>>x;
    int key = hashkey(x);
    HTable[key]=x;
    elementsNo=elementsNo+1;
    loadFactor = (double)elementsNo/size;
    cout<<loadFactor<<endl;
    if(loadFactor>0.5){
        rehashing();
    }
}
void HashTable::Delete(){
    cout<<"enter a value : ";
     int x;
     cin>>x;
    int key = hashkey(x);
    HTable[key]=0;
}
void HashTable::Show(){
    cout<<"\tIndex\t:\tValue\t"<<endl;
    for(int i=0;i<size;i++){

        cout<<"\t"<<i<<"\t:\t"<<HTable[i]<<"\t"<<endl;
    }
}
void HashTable::Searching(){
     cout<<"enter a value : ";
     int x;
     cin>>x;
    int key = hashkey(x);
    cout<<"value found at index :"<<key<<endl;
}
void HashTable::rehashing(){
    vector<int>arr(size,0);
    for(int i=0;i<size;i++){
        arr[i]=HTable[i];
        HTable[i]=0;
    }
    size=size*2;
    HTable.resize(size,0);
    for(int i=0;i<size/2;i++){
        if(arr[i]!=0)
        HTable[hashkey(arr[i])]=arr[i];
    }

}
int HashTable::hashkey(int x){
   if(HTable[x%size]==0)
       return x%size;
    else{
        int i;
        for( i=1;i<size;i++){
            int key = ((x%size)+i)%size;
            if(HTable[key]==0){
                return x%size;
            }
        }

    }
}
int main(){
    HashTable h;
  while(1){
    cout<<"1.Insert()\n2.Delete()\n3.Show()\n4.Searching()"<<endl;
    cout<<"enter your choice: ";
    int c;
    cin>>c;
    if(c==1){

        h.Insert();
    }
    else if(c==2){
        h.Delete();
    }
    else if(c==3){
        h.Show();
    }
    else if(c==4){
        h.Searching();
    }
    else{
        break;
    }

  }
  return 0;
}


