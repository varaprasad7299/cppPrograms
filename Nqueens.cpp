#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int* x;
int n;

bool Place(int k,int i){
    for(int j = 0;j < k;j++){
        if((x[j] == i) || (abs(x[j] - i) == abs(j -k)))
            return false;
    }
    return true;
}

void print(){
    static int i = 1;
    if(i == 1) cout <<"----------Printing Solutions---------"<<endl;
    cout<<"Solution "<<i++<<" : [";
    for(int i = 0;i < n;i++)
        cout<<x[i]<<" ";
    cout<<"\b]"<<endl;
}

void NQueens(int k){
    for(int i = 0;i < n;i++){
        if(Place(k,i)){
            x[k] = i;
            if(k == n-1)
                print();
            else NQueens(k+1);
        }
    }
}

int main()
{
    cout << "Enter No.of Queens : ";
    cin >> n;
    x = (int*)calloc(n,sizeof(int));
    NQueens(0);
}