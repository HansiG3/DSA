#include<iostream>
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
    cout<<"enter value for left of "<<root->data;
    root->left=create(root->left);
    cout<<"enter value for right of "<<root->data;
    root->right=create(root->right);
    return root;
}
node* lca(node*root,int num1,int num2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==num1||root->data==num2){
        return root;
    }
    node* leftans=lca(root->left,num1,num2);
    node*rightans=lca(root->right,num1,num2);
    if(leftans!=NULL&rightans!=NULL){
        return root;
    }
    else if(leftans!=NULL&&rightans==NULL){
        return leftans;
    }
    else if(leftans==NULL&&rightans!=NULL){
        return rightans;
    }
    else{
        return NULL;
    }
}
int main(){
    node*root=NULL;
    root=create(root);
    int num1,num2;
    cin>>num1>>num2;
    node*ans=lca(root,num1,num2);
    cout<<ans->data;
}