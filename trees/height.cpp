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
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
int main(){
    node*root=NULL;
    root=create(root);
    int a=height(root);
    cout<<"the height of binary tree is "<<a;
}