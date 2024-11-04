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
void levelorder(node*root){
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
bool search(node* root,int d){
    if(root==NULL){
        return false;
    }
    if(d==root->data){
        return true;
    }
    else if(d>root->data){
        return search(root->right,d);
    }
    else{
        return search(root->left,d);
    }
}

node* min_value(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* todelete(node*root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }

        //2 children
        if(root->left!=NULL && root->right!=NULL){
            int min=min_value(root->right)->data;  // either right subtree ki min value or left subtree ki max value=min->data;
            root->right=todelete(root->right,min);
            return root;
        }
    }
    else if(root->data>val){
        root->left=todelete(root->left,val);
    }
    else{
        root->right=todelete(root->right,val);
    }
    return root;
}
int main(){
    node* root=NULL;
    int d;
    cin>>d;
    while(d!=-1){
        root=create(root,d);
        cin>>d;
    }
    levelorder(root);
    // int value;
    // cout<<"enter the value you want to find ";
    // cin>>value;
    // bool ans=search(root,value);
    // cout<<ans; 
    cout<<endl;
    root=todelete(root,5);
    levelorder(root);
}