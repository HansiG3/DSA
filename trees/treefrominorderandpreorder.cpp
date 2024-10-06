#include<iostream>
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
node* create(int in[],int pre[],int &preindex,int instartindex,int inendindex,int size,map<int,int>m){
    if(preindex>=size||instartindex>inendindex){
        return NULL;
    }
    int element=pre[preindex++];
    node* root=new node(element);
    int pos=m[element];

    root->left=create(in,pre,preindex,instartindex,pos-1,size,m);
    root->right=create(in,pre,preindex,pos+1,inendindex,size,m);

    return root;
}
void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
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
    int size;
    cout<<"enter the size "<<endl;
    cin>>size;
    int *in=new int[size];
    int *pre=new int[size];
    map<int,int>m;
    cout<<"enter the inorder elements "<<endl;
    for(int i=0;i<size;i++){
        cin>>in[i];
        m[in[i]]=i;
    }
    cout<<"enter the preorder elements "<<endl;
    for(int i=0;i<size;i++){
        cin>>pre[i];
    }
    int preindex=0;
    int instartindex=0;
    int inendindex=size-1;
    node* ans=create(in,pre,preindex,instartindex,inendindex,size,m);
    levelordertraversal(ans);
}
