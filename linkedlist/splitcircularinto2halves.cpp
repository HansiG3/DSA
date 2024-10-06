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
void half(node *&tail){
    node*temp=tail;
    int count=1;
    while(temp!=tail){
        count++;
        temp=temp->next;
    }
    int pos=1;
    while(pos<count/2){
        
    }
}