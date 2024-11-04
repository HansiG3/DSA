#include<iostream>
#include<stack>
#include<queue>
#include<map>
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
void visitednodes(node* root, map<node*,bool>&visited) {
    queue<node*> q;
    q.push(root);
    visited[root] =false;
    
    while(!q.empty()) {
        node* front = q.front();
        visited[front]=false;
        q.pop();
        
        if(front->left) {
            q.push(front->left);
        }
        
        if(front->right) {
            q.push(front->right);
        }
    }
}
void inorder(node*root,map<node*,bool>&visited){
    stack<node*>s;
    s.push(root);
    visited[root]=true;
    while(!s.empty()){
        node* top=s.top();
        if(top->left!=NULL &&visited[top->left]==false){
            visited[top->left]=true;
            s.push(top->left);
        }
        else{
            if(top->left==NULL && top->right==NULL){
                cout<<root->data<<" ";
                s.pop();
            }
            top=s.top();
            cout<<top->data<<" ";
            s.pop();
            if(top->right!=NULL && visited[top->right]==false){
                s.push(top->right);
                visited[top->right]=true;
            }
        }
    }
}
int main(){
    node* root=NULL;
    root=binarytree(root);
    map<node*,bool>visited;
    visitednodes(root,visited);
    inorder(root,visited);
}