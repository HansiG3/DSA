#include<iostream>
using namespace std;
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
pair<bool,int> sum(node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int>leftans=sum(root->left);
    pair<bool,int>rightans=sum(root->right);
    bool left=leftans.first;
    bool right=rightans.first;
    bool val=root->data==leftans.second+rightans.second;
    pair<bool,int>ans;
    if(left&&right&&val){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}
int main(){
    node* root=NULL;
    root=binarytree(root);
    pair<bool,int>ans=sum(root);
    cout<<ans.first;
}