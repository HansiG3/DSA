#include<iostream>
#include<queue>
using namespace std; 
class node{
    public:
    int data; 
    int height;
    node* left; 
    node* right;
    node(int data){
        this->data=data;
        height=1;
        left=NULL;
        right=NULL;
    }
};
int height(node*root){
    if(root==NULL){
        return 0;
    }
    else{
        return(root->height);
    }
}
node* rightrotate(node*root){
    node* x=root->left;
    node* t2=x->right;
    x->right=root; 
    root->left=t2; 
    x->height=1+max(height(x->left),height(x->right));
    root->height=1+max(height(root->left),height(root->right));
    return x;
}
node* leftrotate(node* root){
    node* x=root->right;
    node* t2=x->left;
    x->left=root;
    root->right=t2;
    x->height=1+max(height(x->left),height(x->right));
    root->height=1+max(height(root->left),height(root->right));
    return x;
}
int balancefactor(node*root){
    return(height(root->left)-height(root->right));
}
node* insert(node*root,int d){
    if(root==NULL){
        node* newnode=new node(d);
        return newnode;
    }
    if(d>root->data){
        root->right=insert(root->right,d);
    }
    if(d<root->data){
        root->left=insert(root->left,d);
    }
    root->height=1+max(height(root->left),height(root->right));
    int bal=balancefactor(root);
    if(bal>1&&d<root->data){
        return rightrotate(root);
    }
    if(bal<-1&&d>root->data){
        return leftrotate(root);
    }
    if(bal>1&&d>root->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(bal<-1&&d<root->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
node* getmin(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* deletenode(node*root,int d){
    if(root==NULL){
        return root;
    }
    if(d>root->data){
        root->right=deletenode(root->right,d);
    }
    if(d<root->data){
        root->left=deletenode(root->left,d);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL&&root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->left!=NULL&&root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            int mini=getmin(root->right)->data;
            root->data=mini;
            root->right=deletenode(root->right,mini);
        }
        return root;
    }
    
    root->height=1+max(height(root->left),height(root->right));
    int bal=balancefactor(root);
    if(bal>1&&d<root->data){
        return rightrotate(root);
    }
    if(bal<-1&&d>root->data){
        return leftrotate(root);
    }
    if(bal>1&&d>root->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(bal<-1&&d<root->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void levelorder(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    node*root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,20);
    root=insert(root,18);
    levelorder(root);
    root=deletenode(root,18);
    levelorder(root);
}