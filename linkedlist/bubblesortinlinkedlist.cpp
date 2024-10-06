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
        if(head==NULL){
            head=temp;
        }
        else{
        temp->next=head;
        head=temp;
    }
}
void bubblesort(node*&head){
    int count=1;
    int size=0;
    node* temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    temp=head;
    int flag=0;
    node* temp1=temp->next;
    while(count<size){
        temp=head;
        temp1=temp->next;
        while(temp1!=NULL){
            if(temp1->data<temp->data){
                int t=temp->data;
                temp->data=temp1->data;
                temp1->data=t;
                flag=1;
            }
            temp1=temp1->next;
            temp=temp->next;
        }
        if(flag==0){
            break;
        }
        temp=temp->next;
        count++;
    }
}
void print(node*head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}
int main(){
    node* head=NULL;
    insertathead(head,4);
    insertathead(head,5);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,1);
    bubblesort(head);
    print(head);
}