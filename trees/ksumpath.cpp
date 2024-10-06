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
void ksum(node* root,int k,int &count,vector<int>&v){
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    ksum(root->left,k,count,v);
    ksum(root->right,k,count,v);
    int sum=0;
    for(int i=v.size()-1;i>=0;i--){
        sum+=v[i];
        if(k==sum){
            count++;
        }
    }
    v.pop_back();
}
int main(){
    node* root=NULL;
    root=create(root);
    int k;
    cout<<"enter value for k";
    cin>>k;
    int count=0;
    vector<int>v;
    ksum(root,k,count,v);
    cout<<count;
}