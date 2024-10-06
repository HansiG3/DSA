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
void reverse(node *&head){
    node*curr=head;
    node*prev=NULL;
    node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
}
void add(node *&head1,node *&head2,node *&head3){
    int carry=0;
    reverse(head1);
    reverse(head2);
    node *temp1=head1;
    node *temp2=head2;
    node *temp3=head3;
    node *t=head3;
    while(temp1!=NULL&&temp2!=NULL){
        int sum=temp1->data+temp2->data+carry;
        int digit=sum%10;
        head3->next=new node(digit);
        carry=sum/10;
        temp1=temp1->next;
        temp2=temp2->next;
        head3=head3->next;
    }
     while(temp1!=NULL){
        int sum=temp1->data+carry;
        int digit=sum%10;
       head3->next=new node(digit);
        carry=sum/10;
        temp1=temp1->next;
        head3=head3->next;
    }
    while(temp2!=NULL){
        int sum=temp2->data+carry;
        int digit=sum%10;
       head3->next=new node(digit);
        carry=sum/10;
        temp2=temp2->next;
        head3=head3->next;
    }
    if(carry!=0)
    {
        int sum=carry;
        int digit=sum%10;
        head3->next=new node(digit);
    }
    temp3=temp3->next;
    reverse(temp3);
    delete t;
}
void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node *node1=new node(1);
    node1->next=new node(2);
    node1->next->next=new node(9);
    node *node2=new node(4);
    node2->next=new node(5);
    node *temp3=new node(-1);
    node *head3=temp3;
    add(node1,node2,head3);
    print(head3);
    
}