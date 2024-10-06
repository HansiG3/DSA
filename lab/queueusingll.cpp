#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int data){
        this->next=NULL;
        this->data=data;
    }
};
class queue{
    public:
    node* front;
    node* rear;
    queue(){
        this->front=this->rear=NULL;
    }
    void enqueue(int value){
    node* temp=new node(value);
    if(rear==NULL){
        front=rear=temp;
        return;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
    void dequeue(){
        if(front==NULL){
            cout<<"queue is empty ";
            return;
        }
        else{
            node* temp=front;
            front=front->next;
            delete temp;
        }
    }
    void peek(){
        if(front==NULL){
            cout<<"-1";
        }
        cout<<front->data;
    }
    bool isempty(){
        if(front==NULL &&rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();
    q.dequeue();
    cout<<endl;
    q.print();
}