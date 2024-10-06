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
void insertatposition(node *&head,node *&tail,int position,int d){
    if(position==1){
        insertathead(head,d);
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
            insertattail(tail,d);
        }
        nodetoinsert->next=temp->next;
        temp->next=nodetoinsert;
    }
}
void mid(node *&head){
    int count=0;
    node *t=head;
    while(t!=NULL){
        count++;
        t=t->next;
    }
    int ans=count/2;
    int c=0;
    node *temp=head;
    while(c<ans){
        temp=temp->next;
        c++;
    }
    cout<<temp->data<<endl;;
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
    node *node1=new node(10);
    node *head=node1;
    node *tail=node1;
    insertathead(head,2);
    insertattail(tail,7);
    insertatposition(head,tail,3,6);
    mid(head);
}
