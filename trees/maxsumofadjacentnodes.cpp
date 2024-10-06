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
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    cout<<"enter data for left of "<<root->data;
    root->left=create(root->left);
    cout<<"enter data for right of "<<root->data;
    root->right=create(root->right);
    return root;
}
// FIRST VALUE OF PAIR MAI INCLUDE KARA HAIN CURRENT NODE KO SECOND MAI EXCLUDE
pair<int,int> solve(node*root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);
    pair<int,int>result;
    result.first=root->data+left.second+right.second;
    result.second=max(left.first,left.second) + max(right.first,right.second);
    return result;
}
int main(){
    node*root=NULL;
    root=create(root);
    pair<int,int>ans;
    ans=solve(root);
    cout<<max(ans.first,ans.second);
    }