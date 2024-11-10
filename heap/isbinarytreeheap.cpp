#include<iostream>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    int data;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node* binarytree(node* root){
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter the data for left of node "<<data;
    root->left=binarytree(root->left);
    cout<<"enter the data for right of node "<<data;
    root->right=binarytree(root->right);
    return root;
}
int countnodes(node*root){
    if(root==NULL){
        return 0;
    }
    else{
        return(1+countnodes(root->left)+countnodes(root->right));
    }
}
bool cbt(node*root,int index,int count){
    if(root==NULL){
        return true;
    }
    if(index>=count){
        return false;
    }
    bool left=cbt(root->left,2*index+1,count);
    bool right=cbt(root->right,2*index+2,count);
    return left&&right;
}
bool ismax(node*root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return(root->data>root->right->data);
    }
    else{
        bool ans=root->data>root->right->data && root->data>root->left->data;
        bool left=ismax(root->left);
        bool right=ismax(root->right);
        return ans&&left&&right;
    }
}
int main(){
    node*root=NULL;
    root=binarytree(root);
    int index=0;
    int count=countnodes(root);
    bool ans=cbt(root,index,count)&&ismax(root);
    cout<<ans;
}