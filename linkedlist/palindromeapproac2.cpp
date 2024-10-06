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
node* getmiddle(node *&head){
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void reverselist(node*&head){
    node *curr=head;
    node*prev=NULL;
    node *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
}
void ispalindrome(node *&head){
    node *middle=getmiddle(head);
    node *head1=head;
    node *head2=middle->next;
    int flag=1;
    reverselist(head2);
    node *temp2=head2;
    while(temp2!=NULL){
        if(head1->data!=temp2->data){
            flag=0;
            break;
        }
        head1=head1->next;
        temp2=temp2->next;
    }
    if(flag==1){
        cout<<"is a palindrome "<<endl;
    }
    else{
        cout<<"not a palindrome ";
    }
}
int main(){
    node *head1=new node(10);
    head1->next=new node(20);
    head1->next->next=new node(30);
    head1->next->next->next=new node(10);
    ispalindrome(head1);
}