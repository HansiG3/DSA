#include<iostream>
#include<queue>
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
node* create(node* root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=create(root->right,d);
    }
    else{
        root->left=create(root->left,d);
    }
    return root;
}
void inorder(node*root,int &i,int k){
    if(root==NULL){
        return;
    }
    inorder(root->left,i,k);
    i++;
    if(i==k){
        cout<<root->data;
        return;
    }
    inorder(root->right,i,k);
}
void ksmall(node* root,int k){
    int i=0;
    inorder(root,i,k);
}
int main(){
    node* root=NULL;
    int d;
    cin>>d;
    while(d!=-1){
        root=create(root,d);
        cin>>d;
    }
    int k;
    cout<<"enter value of k ";
    cin>>k;
    ksmall(root,k);
}