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
void insertnode(node *&tail,int element,int d){
    if(tail==NULL){
        node *temp=new node(d);
        tail=temp;
        temp->next=temp;
    }
    else{
        //assuming element exist in that linked list
        node *curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node *temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(node *tail){
    if(tail==NULL){
        cout<<"empty list "<<endl;
        return;
    }
    node *temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
void deletenode(node *&tail,int value){
    if(tail==NULL){
        cout<<"list is already empty "<<endl;
        return;
    }
    
    else{
        node *prev=tail;
        node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        //>=2 ki linked list ki condition
        if(tail==curr){
            tail=prev;
        }
        //1 node linked list curr prev tail same par point so error dega
        if(curr==prev){
            tail=NULL;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){
    node *tail=NULL;
    insertnode(tail,3,5);
    //print(tail);
    insertnode(tail,5,7);
    /*print(tail);
    insertnode(tail,7,9);
    print(tail);
    insertnode(tail,5,1);
    print(tail);*/
    deletenode(tail,7);
    print(tail);
}