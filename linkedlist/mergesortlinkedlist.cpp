#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=next;
    }
};
node *getmid(node *&head){
    node *fast=head->next;
    node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* mergelist(node *left,node *right){
    node *ans=new node(-1);
    node *temp=ans;
    node *t=ans;
    node *head1=left;
    node *head2=right;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            temp->next=new node(head1->data);
            head1=head1->next;
        }
        else{
            temp->next=new node(head2->data);
            head2=head2->next;
        }
        temp=temp->next;
    }
    if(head1!=NULL){
        temp->next=new node(head1->data);
        head1=head1->next;
        temp=temp->next;
    }
    if(head2!=NULL){
        temp->next=new node(head2->data);
        head2=head2->next;
        temp=temp->next;
    }
    ans=ans->next;
    delete t;
    return ans;
}
node* mergesort(node *&head){
    if(head==NULL ||head->next==NULL){
        return;
    }
    node *mid=getmid(head);
    node *left=head;
    node *right=mid->next;
    mid->next=NULL;

    left=mergesort(left);
    right=mergesort(right);

    node*result=mergelist(left,right);
    return result;
}
void print(node*&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node *head=new node(10);
    head->next=new node(5);
    head->next->next=new node(45);
    head->next->next->next=new node(3);
    node *head2=mergesort(head);
    print(head2);
}
