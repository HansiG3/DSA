#include<iostream>
#include<vector>
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
vector<int>bottomview(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>m;  // first int is for horizontal level and second for node->data
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        node* frontnode=temp.first;
        int hd=temp.second;
        m[hd]=frontnode->data;
        if(frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    node*root=NULL;
    root=create(root);
    vector<int>result=bottomview(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}