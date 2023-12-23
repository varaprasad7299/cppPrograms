#include<iostream>
using namespace std;
#include<string.h>
int main(){
  int n;
  cout<<"text length : ";
  cin>>n;
  char text[n];
  //fflush(stdin);
  cout<<"enter text : "<<endl;
 // cin.getline(text,n);
 cin>>text;
  // fflush(stdin);
  int m;
  cout<<"pattern length : ";
  cin>>m;
  //fflush(stdin);
  char p[m];
  cout<<"enter pattern : "<<endl;
  //cin.getline(p,m);
  cin>>p;
  // call kmp method
  for(int i=0;i<n-m;i++){
    int j;
    for(j=0;j<m;j++){
        if(text[i+j]!=p[j]){
            cout<<text[i+j]<<" "<<p[j]<<endl;
            break;
        }
    }
        cout<<text[i+j]<<" "<<p[j]<<endl;
        if(j==m){
            cout<<"pattern found at : "<<i<<endl;
        }
    }

   return 0;

}
