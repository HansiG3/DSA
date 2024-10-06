#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* create(node* root){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    cout<<"enter data for left of "<<root->data;
    root->left=create(root->left);
    cout<<"enter data for right of "<<root->data;
    root->right=create(root->right);
    return root;
}
void kancesstor(node* root,vector<int>&v,int k,int num){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    kancesstor(root->left,v,k,num);
    kancesstor(root->right,v,k,num);
    if(root->data==num){
        if(v.size()>k)
            cout<<v[v.size()-k-1];
    }
    v.pop_back();
}
int main(){
    node* root=NULL;
    root=create(root);
    int num; 
    int k;
    cout<<"enter the number ";
    cin>>num;
    cout<<"enter the ancesstor number ";
    cin>>k;
    vector<int>v;
    kancesstor(root,v,k,num);
}