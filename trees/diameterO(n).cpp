#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
node* create(node* root){
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for left of "<<data;
    root->left=create(root->left);
    cout<<"enter data for right of "<<data;
    root->right=create(root->right);
    return root;
}
pair<int,int>diameter(node* root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=diameter(root->left);
    pair<int,int>right=diameter(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}