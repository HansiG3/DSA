#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* push(node*&head,int value){
    node* temp1=new node(value);
    if(head==NULL){
        head=temp1;
    }
    else{
        temp1->next=head;
        head=temp1;
        
    }
    return head;
}
void bubblesort(node*&head){
    bool swapped;
    do{
        swapped=false;
        node*current=head;
        node*forward=NULL;
        while(current->next!=NULL){
            forward=current->next;
            if(current->data>forward->data){
                int temp=current->data;
                current->data=forward->data;
                forward->data=temp;
                swapped=true;
            }
            current=current->next;
        }
    }while(swapped);
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node*head=NULL;
    head=push(head,70);
    head=push(head,30);
    head=push(head,7);
    head=push(head,9);
    bubblesort(head);
    print(head);
}