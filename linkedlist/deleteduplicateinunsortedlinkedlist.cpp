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
void sortlist(node *&head){
    if(head==NULL){
        return;
    }
    else{
        node *temp=head;
        while(temp!=NULL){
            node *t=temp->next;
            while(t!=NULL){
                if(temp->data>t->data){
                    int value=temp->data;
                    temp->data=t->data;
                    t->data=value;
                }
                t=t->next;
            }
            temp=temp->next;
        }
    }
}
void deleteduplicate(node *&head){
    if(head==NULL){
        return;
    }
    else{
        sortlist(head);
        node *temp=head;
        if(head==NULL){
            return;
        }
        while(temp!=NULL&&temp->next!=NULL){
            if(temp->data==temp->next->data){
                node *t=temp->next;
                temp->next=temp->next->next;
                delete t;
            }
            else{
                temp=temp->next;
            }

        }
    }
}
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node *node1=new node(20);
    node *node2=new node(10);
    node *node3=new node(20);
    node *node4=new node(20);
    node *node5=new node(30);
    node *node6=new node(10);
    node *node7=new node(30);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    
    node *head=node1;
    deleteduplicate(head);
    print(head);
}