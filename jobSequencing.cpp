#include<iostream>
using namespace std;


class Job{
    public:

   double profit;
   int deadline;
   void setProfit(){
       cout<<"enter job Profit: ";
       cin>>profit;
   }
   void setDeadline(){
       cout<<"enter the deadline :";
       cin>>deadline;
   }



};
int checkMaxPf(Job j[],int n){
    double m=0.0;
    int index=0;
   // int n=j.jobNo;
    for(int i=0;i<n;i++){
        if(j[i].profit>=m){
            m=j[i].profit;
            index=i;
        }
    }
    return index;
}
int main(){
  int n,maxDeadline=0;
  cout<<"enter the no of jobs :";
  cin>>n;
  Job j[n];
  for(int i=0;i<n;i++){
    cout<<"enter the job"<<i+1<<" details"<<endl;
    j[i].setProfit();
    j[i].setDeadline();
    if(maxDeadline<=j[i].deadline)
        maxDeadline=j[i].deadline;
  }
  double pf[maxDeadline]={0.0};
  for(int i=0;i<n;i++){
      int ind=checkMaxPf(j,n);
    if(pf[j[ind].deadline-1]==0.0)
       pf[j[ind].deadline-1]=j[ind].profit;
    else{

    }
    j[ind].profit=0.0;
  }
  double sum=0.0;
  for(int i=0;i<maxDeadline;i++){

    sum+=pf[i];
  }
   cout<<"total profit :"<<sum<<endl;
   return 0;
  }

