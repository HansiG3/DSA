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
void mergelist(node *&head1,node *&head2,node *&head3){
    node *temp1=head1;
    node *temp2=head2;
    node *t=head3;
    node *deletenode=t;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            t->next=temp1;
            temp1=temp1->next;
        }
        else{
            t->next=temp2;
            temp2=temp2->next;
        }
        t=t->next;
    }
    if(temp1!=NULL){
        t->next=temp1;
        t=t->next;
        temp1=temp1->next;
    }
    else{
        t->next=temp2;
        t=t->next;
        temp2=temp2->next;
    }
    head3=head3->next;
    delete deletenode;
    }
void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node *head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(3);

    // Creating second sorted linked list: 2 -> 4 -> 6
    node *head2 = new node(2);
    head2->next = new node(4);
    head2->next->next = new node(6);

    node *dummyhead=new node(-1);
    node *head3=dummyhead;

    mergelist(head1, head2,head3);

    // Print the merged list
    print(head3);

    return 0;
}
