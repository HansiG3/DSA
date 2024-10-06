#include<iostream>
#include<vector>
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
vector<int> zigzag(node* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    queue<node*> q;
    q.push(root);
    bool leftoright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            node* frontnode=q.front();
            q.pop();
            int index=leftoright?i:size-i-1;
            temp[index]=frontnode->data;
            if(frontnode->left){
                q.push(frontnode->left);
            }
            if(frontnode->right){
                q.push(frontnode->right);
            }
        }
        leftoright=!leftoright;
        for(auto i:temp){
            result.push_back(i);
        }
    }
    return result;
    }
int main(){
    node* root=NULL;
    root=create(root);
    vector<int>ans=zigzag(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
