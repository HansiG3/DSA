#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertathead(node *&head,int d){
    node *nodetoinsert=new node(d);
    nodetoinsert->next=head;
    head=nodetoinsert;
}
void insertattail(node *&tail,int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertatposition(node *&head,node *&tail, int position,int d){
    if(position==1){
        insertathead(head,d);
        return;
    }
    node *temp=head;
    node *nodetoinsert=new node(d);
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
void reversenode(node *&head){
    node *curr=head;
    node *prev=NULL;
    node *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
}
void print (node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node *node1=new node(10);
    node *head=node1;
    node *tail=node1;
    insertathead(head,7);
    insertattail(tail,8);
    insertatposition(head,tail,2,9);
    reversenode(head);
    print(head);
}