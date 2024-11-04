#include<iostream>
#include<stack>
#include<map>
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
    cout<<"enter left value for "<<root->data;
    root->left=create(root->left);
    cout<<"enter right value for"<<root->data;
    root->right=create(root->right);
    return root;
    }
void preorder(node* root){
    stack<node*>s;
    s.push(root);
    map<node*,bool>m;
    m[root]=false;
    while(!s.empty()){
        node* top=s.top();
        if(m[top]==false){
            cout<<top->data;
            m[top]=true;
        }
        if(top->left!=NULL && m.find(top->left)==m.end()){
            s.push(top->left);
            top=s.top();
            m[top]=false;
        }
        else{
            if(top->left==NULL && top->right==NULL){
                s.pop();
                if(s.empty()){
                    break;
                }
            }
            top=s.top();
            s.pop();
            if(top->right!=NULL && m.find(top->right)==m.end()){
                s.push(top->right);
                m[top->right]=false;
            }

        }
    }
}

int main(){
    node* root=NULL;
    root=create(root);
    preorder(root);
    return 0;
}
    