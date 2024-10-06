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
        left=NULL;
        right=NULL;
    }
};
node* create(node* root){
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
void leftview(node* root,int level,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    leftview(root->left,level+1,ans);
    leftview(root->right,level+1,ans);
}
int main(){
    vector<int>ans;
    int level=0;
    node* root=NULL;
    root=create(root);
    vector<int>result;
    leftview(root,level,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    }
    