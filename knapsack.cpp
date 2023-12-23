#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct object{
    int weight,profit;
    float pw;
    int id;
};
bool compare(object o1,object o2){
    return o1.pw>o2.pw;
}
int main(){
    vector<object> o;
    vector<float> x;
    object o1;
    int m,n,i;
    float profit=0.0;
    cout<<"Enter number of objects\n";
    cin>>n;
    cout<<"Enter capacity of knapsack or bag\n";
    cin>>m;
    cout<<"enter weight and profit for each object\n";
    for(int i=0;i<n;i++){
        cin>>o1.weight>>o1.profit;
        o1.pw=(float)o1.profit/o1.weight;
        o1.id=i;
        o.push_back(o1);
        x.push_back(0.0);
    }
    sort(o.begin(),o.end(),compare);
    for(int j=0;j<o.size();j++)
      cout<<o[j].weight<<"\t"<<o[j].profit<<"\t"<<o[j].pw<<endl;
   // x[o[0].id]=1.0;
   // m=m-o[0].weight;
    for(i=0;i<o.size();i++){
        if(o[i].weight<=m){
            m=m-o[i].weight;
            x[o[i].id]=1.0;
            profit=profit+(float)o[i].profit;
        }
        else
            break;
    }
    if(i<o.size()){
        x[o[i].id]=(float)m/o[i].weight;
        profit=profit+(((float)o[i].profit)*((float)m/o[i].weight));
    }
    cout<<"solution vector is\n"<<"[";
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    cout<<"]"<<endl;
    cout<<"Total profit is :"<<profit<<endl;
    return 0;
}
