#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int data){
        this->data=data;
        this->next=this->prev=NULL;
    }
};
void print(node *head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(node *head){
    int count=0;
    node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void insertathead(node*&head,node *&tail,int d){
    if(head==NULL){
        node *nodetoinsert=new node(d);
        head=nodetoinsert;
        tail=nodetoinsert;
    }
    else{
        node *nodetoinsert=new node(d);
        nodetoinsert->next=head;
        head->prev=nodetoinsert;
        head=nodetoinsert;
    }
}

void insertattail(node *&tail,node *&head,int d){
    if(tail==NULL){
        node *temp=new node(d);
        head=temp;
        tail=temp;
    }
    node *temp=new node(d);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void insertatposition(node *&head,node *&tail,int position,int d){
    if(position==1){
        insertathead(head,tail,d);
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
            insertattail(tail,head,d);
            return;
        }
        else{
            nodetoinsert->next=temp->next;
            temp->next->prev=nodetoinsert;
            temp->next=nodetoinsert;
            nodetoinsert->prev=temp;
        }
    }
}
void deletenode(node *&head,node *&tail,int position){
    if(position==1){
        node *temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node *current=head;
        node *previous=NULL;
        int count=1;
        while(count<position){
            previous=current;
            current=current->next;
            count++;
        }
        if(current->next==NULL){
            previous->next=NULL;
            current->prev=NULL;
            delete current;
            return;
        }
        previous->next=current->next;
        current->next->prev=previous;
        current->prev = NULL;
        current->next = NULL;
        delete current;
    }
}
int main(){
    node *node1=new node(10);
    node *head=NULL;// node *head=node1 waala concept is sahi yeh just to check the empty case
    node *tail=NULL;
    print(head);
    int len=getlength(head);
    cout<<"length "<<len<<endl;
    insertathead(head,tail,21);
    print(head);
    insertattail(tail,head,6);
    print(head);
    insertatposition(head,tail,2,55);
    print(head);
    insertatposition(head,tail,1,5);
    print(head);
    insertatposition(head,tail,5,89);
    print(head);
    deletenode(head,tail,5);
    print(head);
}