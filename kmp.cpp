#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void lps(char *p,int m,int *l){
   int i=1;
   int len=0;
   l[0]=0;
   while(i<m){
    if(p[i]==p[len]){
        len++;
        l[i]=len;
        i++;
    }
    else{
        if(len!=0){
            len=l[len-1];
        }
        else{
            l[i]=0;
            i++;
        }
    }
   }

}
void kmp(char *text,char *p){
   int n = strlen(text);
   int m = strlen(p);
   int l[m];
   lps(p,m,l);
   int i=0;
   int j=0;
   while(i<n){
     if(text[i]==p[j]){
        i++;
        j++;
     }
     if(j==m){
        cout<<"pattern found at "<<i-j<<endl;
        j=l[j-1];
     }
     else if(i<n && text[i]!=p[j]){
        if(j!=0){
            j=l[j-1];
        }
        else{
            i++;
        }
     }
   }
}
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
  kmp(text,p);


}
