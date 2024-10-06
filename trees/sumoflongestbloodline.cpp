#include<iostream>
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
    cout<<"enter value for left of "<<root->data;
    root->left=create(root->left);
    cout<<"enter value for right of "<<root->data;
    root->right=create(root->right);
    return root;
}
void max_sum(node* root,int sum,int &maxsum,int length,int &maxlen){
    if(root==NULL){
        if(length>maxlen){
            maxlen=length;
            sum=sum;
        }
        else if(maxlen==length){
            maxsum=max(maxsum,sum);
        }
        return;
    }
    sum=sum+root->data;
    max_sum(root->left,sum,maxsum,length+1,maxlen);
    max_sum(root->right,sum,maxsum,length+1,maxlen);
}
int main(){
    node*root=NULL;
    root=create(root);
    int sum=0;
    int maxsum=0;
    int length=1;
    int maxlen=0;
    max_sum(root,sum,maxsum,length,maxlen);
    cout<<"maximum sum is "<<maxsum;
}