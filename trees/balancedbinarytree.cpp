// a tree is balanced if the difference between left and right tree height is not more than one for all nodes
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
int balanced(node* root,bool &isbalanced){
    if(root==NULL){
        return 1;
    }
    int left=balanced(root->left,isbalanced);
    int right=balanced(root->right,isbalanced);
    if(abs(left-right)>1){
        isbalanced=false;
    }
    return max(left,right)+1;
}
int main(){
    node* root=NULL;
    root=create(root);
    bool isbalanced=true;
    int a=balanced(root,isbalanced);
    cout<<isbalanced;
}