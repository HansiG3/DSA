#include<iostream>
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
bool identiical(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1==NULL&&root2!=NULL){
        return false;
    }
    if(root1!=NULL&&root2==NULL){
        return false;
    }
    bool left=identiical(root1->left,root2->left);
    bool right=identiical(root1->right,root2->right);
    bool val=root1->data==root2->data;
    if(left&&right&&val){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* root=NULL;
    root=binarytree(root);
    node* root1=NULL;
    root1=binarytree(root1);
    bool ans=identiical(root,root1);
    cout<<ans;
}