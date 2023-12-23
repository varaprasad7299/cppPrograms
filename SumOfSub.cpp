#include <iostream>
using namespace std;

int *w,*x;
int n,m,sum = 0;

void print(){
    static int i=1;
    if(i == 1) cout <<"----------Printing Solutions---------"<<endl;
    cout<<"Solution "<<i++<<" : [";
    for(int i = 0;i < n;i++)
        cout << x[i]<<" ";
    cout <<"\b]"<<endl;
}
void SumOfSub(int s,int k,int r){
    x[k] = 1;
    if(s+w[k] == m)
        print();
    else if(s + w[k] + w[k+1] <= m)
        SumOfSub(s+w[k],k+1,r-w[k]);
    if((s+r-w[k] >= m) && s+w[k+1] <= m){
        x[k] = 0;
        SumOfSub(s,k+1,r-w[k]);
    }
        
}

int main(){
    cout<<"Enter no.of elements : ";
    cin >> n;
    w = new int[n];
    x = (int*)calloc(n,sizeof(int));
    cout << "Enter values : ";
    for(int i = 0;i < n;i++){
        cin >> w[i];
        sum += w[i];
    }
    
    cout <<"Enter required sum : ";
    cin >> m;
    if(sum < m || w[0] > m)
        cout <<"No Solution";
    else SumOfSub(0,0,sum);
    return 0;

}