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
void inorder(node*root){
    node* current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            node* predecessor=current->left;
            while(predecessor->right!=NULL&&predecessor->right!=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right=current;
                current=current->left;
            }
            else{
                predecessor->right=NULL;
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}

int main(){
    node* root=NULL;
    root=create(root);
    inorder(root);
}