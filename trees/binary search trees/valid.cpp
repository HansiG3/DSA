#include<iostream>
#include<climits>
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
bool isvalid(node*root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
        bool left=isvalid(root->left,min,root->data);
        bool right=isvalid(root->right,root->data,max);
        return(left&&right);
    }
    return false;
}
int main(){
    node* root=NULL;
    root=create(root);
    int min=INT_MIN;
    int max=INT_MAX;
    bool ans=isvalid(root,min,max);
    cout<<ans;
}
