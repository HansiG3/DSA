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
node* kancesstor(node*root,int num ,int& k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==num){
        return root;
    }
    node* left=kancesstor(root->left,num,k);
    node* right=kancesstor(root->right,num,k);
    if(left!=NULL||right!=NULL){
        k--;
        if(k==0){
        return root;
    }
    return left != NULL ? left : right;
    }
    return NULL;
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
    node* ans=kancesstor(root,num,k);
    if(ans==NULL||ans->data==root->data){
        cout<<"-1";
    }
    else{
        cout<<ans->data;
    }
    
}