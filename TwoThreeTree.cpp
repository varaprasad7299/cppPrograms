#include<iostream>
using namespace std;
class node{
  public:
    int rightData;
    int leftData;
    int num;
    node* left;
    node* right;
    node* middle;
    node(int x){
     left=NULL;
     right=NULL;
     middle=NULL;
     leftData=x;
     num=1;
    }
};
node* createNode(int x){
   // cout<<"E CN F"<<endl;
    node* newNode=new node(x);
    return newNode;
}
bool isLeaf(node* root){
   // cout<<"E ILN F"<<endl;
     if(root->left==NULL){
        return true;
     }
     return false;
}
node* splitNode(node* root, node* newroot,char ch){
   if(ch=='r'){
      //creating new node
      node* temp = createNode(root->leftData);
      temp->left=root->left;
      temp->middle= root->middle;
      // setting root node
      root->leftData=root->rightData;
      root->left=temp;
      root->middle=newroot;
      root->right=NULL;
      newroot->num=1;
      return root;
   }
   if(ch=='l'){
       //creating new node
      node* temp = createNode(root->rightData);
      temp->left=root->middle;
      temp->middle= root->right;
      // setting root node
      root->left=newroot;
      root->middle=temp;
      root->right=NULL;
      newroot->num=1;
      return root;
   }
   if(ch=='m'){
        //creating new node
      node* temp1 = createNode(root->leftData);
      temp1->left=root->left;
      temp1->middle= newroot->left;
      node* temp2 = createNode(root->rightData);
      temp2->left=newroot->middle;
      temp2->middle=root->right;
      // setting root node
      root->leftData=newroot->leftData;
      root->middle=temp2;
      root->left=temp1;
      root->right=NULL;
      delete newroot;
      return root;
   }
}
// overloaded function for leaf nodes
node* splitNode(int x,node* root){
   int m,l,r;
   if(x<root->leftData){
      m=root->leftData;
      l=x;
      r=root->rightData;
   }
   if(x<root->leftData && x<root->rightData){
      m=x;
      l=root->leftData;
      r=root->rightData;
   }
   if(x>root->rightData){
      m=root->rightData;
      l=root->leftData;
      r=x;
   }
   root->leftData=m;
   root->left=createNode(l);
   root->middle=createNode(r);
   return root;
}
node* combine(node* root,node* newroot,char ch){
     if(ch=='r'){
        root->rightData=newroot->leftData;
        root->right=newroot->middle;
        root->middle=newroot->left;
        delete newroot;
        return root;
     }
     if(ch=='l'){
        root->right=root->middle;
        root->left=newroot->left;
        root->middle=newroot->middle;
        root->rightData=root->leftData;
        root->leftData=newroot->leftData;
        delete newroot;
        return root;
     }
}
node* insertEle(int x,node* root){
  //  cout<<"E INE F"<<endl;
    if(root==NULL){
    //    cout<<"E RN C "<<endl;
        root=createNode(x);
    //    cout<<"EX CN F"<<endl;
        return root;
    }
    if(!isLeaf(root)){
    //    cout<<"E LN C"<<endl;
       // insertAcording1

       if(x<=root->leftData){
      //      cout<<"E XGRL C"<<endl;
          root->left=insertEle(x,root->left);
       }
       else if(root->num==2){
          if(x>root->leftData && x<=root->rightData){
      //       cout<<"E XGRL XLRR C"<<endl;
             root->middle=insertEle(x,root->middle);
          }
          if(x>root->rightData){
        //     cout<<"E XLRR C"<<endl;
             root->right=insertEle(x,root->right);
          }
        }
        else{
         //    cout<<"E XGRL XLRR C"<<endl;
             root->middle=insertEle(x,root->middle);
        }
    }
    if(isLeaf(root)){
        if(root->num==1){
        //insert according 2
    //    cout<<"E RNM = 1 C "<<endl;
           if(x>root->leftData){
              root->rightData=x;
              root->num=2;
              return root;
           }
           else{
            int t=root->leftData;
            root->leftData=x;
            root->rightData=t;
            root->num=2;
            return root;
           }
        }
        if(root->num==2){
      //    cout<<"E RNM = 2 C "<<endl;
           root=splitNode(x,root);
           root->num=3;
           return root;
        }
    }
    if(root->num=3){
        return root;
    }
   // cout<<"C ITSN"<<endl;
    //checking if there was a node split
    if(root->right->num==3){
        //int n=root->right->leftData;
        if(root->num==2){
            root=splitNode(root,root->right,'r');
            root->num=3;
            return root;
        }
       // if(root->num==1){
       //     //some code
       //     return root;
       // }
    }
    if(root->left->num==3){
        int n=root->left->leftData;
         if(root->num==2){
            root=splitNode(root,root->left,'l');
            root->num=3;
            return root;
        }
        if(root->num==1){
            //some code
            combine(root,root->left,'l');
            root->num=2;
            return root;
        }
    }
       if(root->middle->num==3){
         int n=root->middle->leftData;
         if(root->num==2){
            root=splitNode(root,root->middle,'m');
            root->num=3;
            return root;
        }
        if(root->num==1){
            //some code
             combine(root,root->middle,'r');
             root->num=2;
            return root;
        }
    }

}
node* deleteElement(int x,node* root){
}
void show(node* root){

    if(root==NULL){
       // cout<<"E RN C"<<endl;
        return;
    }
   // cout<<"G RL F"<<endl;
    show(root->left);
    cout<<root->leftData<<" ";
   //  cout<<"G RM F"<<endl;
    show(root->middle);
    if(root->num==2){
        cout<<root->rightData<<" ";
    }
   //  cout<<"G RR F"<<endl;
    show(root->right);

}
int main(){
    node* root =NULL;
    int c;
    cout<<"1.Insert element\n2.Delete element\n3.Show elements\n4.Exit\n";
    while(1){
      cout<<"enter your choice :";
      cin>>c;
      if(c==1){
      int x;
      cout<<"enter the element: ";
      cin>>x;
      root = insertEle(x,root);
      }
      else if(c==2){ int x;
      cout<<"enter the element: ";
      cin>>x;
      }
      else if(c==3){ int x;
          show(root);
          cout<<endl;
      }
      else{
        break;
      }
    }
    return 0;




}
