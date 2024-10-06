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
void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void reverseorderlevel(node* root){
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        s.push(temp);
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    while(!s.empty()){
        if(s.top()==NULL){
            cout<<endl;
        }
        else{
            cout<<s.top()->data;
        }
        s.pop();
    }
}
void inordertraversal(node* root){
    // LNR
    if(root==NULL){
        return;
    }
    else{
        inordertraversal(root->left);
        cout<<root->data;
        inordertraversal(root->right);
    }
}
void preordertraversal(node* root){
    // NLR
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data;
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
void postordertraversal(node* root){
    // LRN
    if(root==NULL){
        return;
    }
    else{
        postordertraversal(root->left);
        postordertraversal(root->right);
        cout<<root->data;
    }
}
int main(){
    node*root=NULL;
    root=binarytree(root);
    reverseorderlevel(root);
    cout<<endl;
    inordertraversal(root);
}