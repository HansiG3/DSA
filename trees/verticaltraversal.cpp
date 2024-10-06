#include<iostream>
#include<vector>
#include<map>
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

node* create(node*root){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    cout<<"enter left value for "<<root->data;
    root->left=create(root->left);
    cout<<"enter right value for "<<root->data;
    root->right=create(root->right);
    return root;
}
vector<int>vertical(node*root){
    vector<int>ans;
    map<int,map<int,vector<int> > >m;
    queue<pair<node*,pair<int,int> > >q;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int> >temp=q.front();
        node* frontnode=temp.first;
        int hd=temp.second.first;
        int level=temp.second.second;
        q.pop();
        m[hd][level].push_back(frontnode->data);
        if(frontnode->left){
            q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));
        }
    }
    for(auto i:m){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    node* root=NULL;
    root=create(root);
    vector<int>result;
    result=vertical(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
    }

