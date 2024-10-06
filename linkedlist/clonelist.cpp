#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *random;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
    }
};void insertattail(node *&head,node*&tail,int d){
    node *temp=new node(d);
    if(head==NULL){
        head=tail=temp;
    }
    tail->next=temp;
    tail=temp;
}
node* clonelist(node *&head){
    node *temp=head;
    node*clonehead=NULL;
    node *clonetail=NULL;
    while(temp!=NULL){
        insertattail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }
    //clone nodes add in between original list
    temp=head;
    node *clonenode=clonehead;
    while(clonenode!=NULL && temp!=NULL){
        node *forward=temp->next;
        temp->next=clonenode;
        temp=forward;

        node *clonenext=clonenode->next;
        clonenode->next=temp;
        clonenode=clonenext;
    }
    //random pointer copy
    temp=head;
    while(temp!=NULL){
        while(temp->next!=NULL){
            while(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
        }
    }
    // reverting back the changes making 2 different lists
    temp=head;
    clonenode=clonehead;
    while(temp!=NULL && clonenode!=NULL){
        temp->next=clonenode->next;
        temp=temp->next;
        if(temp!=NULL){
            clonenode->next=temp->next;
        }
        clonenode=clonenode->next;
    }
    return clonehead;
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    node *head2=clonelist(head);
    print(head2);
}