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
    }
};
node* create(node*root){
    int d;
    cin>>d;
    root=new node(d);
    if(d==-1){
        return NULL;
    }
    cout<<"enter data for left of "<<root->data;
    root->left=create(root->left);
    cout<<"enter data for right of "<<root->data;
    root->right=create(root->right);
    return root;
}
void traverseleft(node* root,vector<int>&ans){
    if(root==NULL||(root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseleft(root->left,ans);
    }
    else{
        traverseleft(root->right,ans);
    }
}
void traverseleaf(node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    //LNR APPROACH SO THAT WE CAN TRAVERSE FROM LEFT TO RIGHT
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}
void traverseright(node*root,vector<int>&ans){
    if(root==NULL||(root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right){
        traverseright(root->right,ans);
    }
    else{
        traverseright(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundarytraversal(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    traverseleft(root->left,ans);
    traverseleaf(root,ans);
    traverseright(root->right,ans);
    return ans;
}
int main(){
    node* root=NULL;
    root=create(root);
    vector<int>v=boundarytraversal(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}