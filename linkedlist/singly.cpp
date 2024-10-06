#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        next=NULL;
    }
    
};
void insertathead(node *&head,int d){
        node *temp=new node(d);
        temp->next=head;
        head=temp;
    }
void insertattail(node *&tail,int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void print(node *&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
void deletenode(node *&head,node *&tail,int position){
    if(position==1){
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node *curr=head;
        node *prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){
    node *node1=new node(10);
    cout<<node1->data<<" ";
    cout<<node1->next<<" ";
    node *head=node1;
    print(head);
    insertathead(head,13);
    print(head);
    node *tail=node1;
    insertattail(tail,15);
    print(head);
    insertatposition(head,tail,2,19);
    insertatposition(head,tail,1,34);
    insertatposition(head,tail,6,65);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deletenode(head,tail,6);
    cout<<tail->data;
}