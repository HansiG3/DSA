#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
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
void leafnodes(node* root,int &count){
    if(root==NULL){
        return;
    }
    leafnodes(root->left,count);
    if(root->left==NULL&&root->right==NULL){
        count++;
    }
    leafnodes(root->right,count);
}
int main(){
    int count=0;
    node* root=NULL;
    root=binarytree(root);
    leafnodes(root,count);
    cout<< count;
}