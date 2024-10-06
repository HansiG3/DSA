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
    temp1->next=head;
    head=temp1;
    return head;
}
void pop(node*&head){
    if(head==NULL){
        cout<<"stack is empty ";
    }
    else{
        node* temp=head;
        head=head->next;
        delete temp;
    }
}
void peek(node*head){
    cout<<head->data;
}
bool isempty(node*&head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    node* head=NULL;
    head=push(head,10);
    head=push(head,30);
    head=push(head,60);
    cout<<endl;
    pop(head);
    peek(head);
    cout<<endl;
    bool ans=isempty(head);
    cout<<ans;
}