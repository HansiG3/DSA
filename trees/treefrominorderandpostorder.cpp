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
node* create(int in[],int post[],int &postindex,int instartindex,int inendindex,int size,map<int,int>m){
    if(postindex<0||instartindex>inendindex){
        return NULL;
    }
    int element=post[postindex--];
    node* root=new node(element);
    int pos=m[element];

    root->right=create(in,post,postindex,pos+1,inendindex,size,m);
    root->left=create(in,post,postindex,instartindex,pos-1,size,m);

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
    int *post=new int[size];
    map<int,int>m;
    cout<<"enter the inorder elements "<<endl;
    for(int i=0;i<size;i++){
        cin>>in[i];
        m[in[i]]=i;
    }
    cout<<"enter the postorder elements "<<endl;
    for(int i=0;i<size;i++){
        cin>>post[i];
    }
    int postindex=size-1;
    int instartindex=0;
    int inendindex=size-1;
    node* ans=create(in,post,postindex,instartindex,inendindex,size,m);
    levelordertraversal(ans);
}