#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int data){
        this->data=data;
        this->next=this->prev=NULL;
    }
};
void insertathead(node*&head,node *&tail,int d){
    if(head==NULL){
        node *nodetoinsert=new node(d);
        head=nodetoinsert;
        tail=nodetoinsert;
    }
    else{
        node *nodetoinsert=new node(d);
        nodetoinsert->next=head;
        head->prev=nodetoinsert;
        head=nodetoinsert;
    }
}

void insertattail(node *&tail,node *&head,int d){
    if(tail==NULL){
        node *temp=new node(d);
        head=temp;
        tail=temp;
    }
    node *temp=new node(d);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void insertatposition(node *&head,node *&tail,int position,int d){
    if(position==1){
        insertathead(head,tail,d);
        return;
    }
    else{
        int count=1;
        node *temp=head;
        node *nodetoinsert=new node(d);
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            insertattail(tail,head,d);
            return;
        }
        else{
            nodetoinsert->next=temp->next;
            temp->next->prev=nodetoinsert;
            temp->next=nodetoinsert;
            nodetoinsert->prev=temp;
        }
    }
}
void reverse(node *&head){
    node *curr=head;
    node *previous=NULL;
    node *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=curr->prev;
        curr->prev=forward;
        previous=curr;
        curr=forward;
    }
    head=previous; 
}
void print(node *head){
    node*temp=head;
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
    insertathead(head,tail,11);
    insertattail(tail,head,5);
    insertatposition(head,tail,2,8);
    reverse(head);
    print(head);
}
