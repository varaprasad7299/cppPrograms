#include<iostream>
using namespace std;
int main(){
   int n;
   cout<<"enter no of vertices : ";
   cin>>n;
   int a[n][n];
   cout<<"enter the graph"<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
   }
   int in[n]={0};
   int vv[n]={0};
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[j][i]==1)
        in[i]++;
    }
   }
   for(int i=0;i<n;i++){
    int j;
    for( j=0;j<n;j++){
        if(in[j]==0 && vv[j]==0){
            cout<<j+1<<" ";
            vv[j]=1;
            break;
        }
    }
    //cout<<j<<endl;
    if(j==n){
        return 0;
    }
    for(int k=0;k<n;k++){
        if(a[j][k]==1){
            in[k]-=1;
        }
    }
   }

}
