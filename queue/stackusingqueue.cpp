#include<iostream>
using namespace std;
class queue{
    public:
    int front;
    int rear;
    int *arr;
    int size;
    queue(int size){
        front=-1;
        rear=-1;
        arr=new int[size];
    }
    void push(int element){
        if(rear==size-1){
            cout<<"queue is full ";
        }
        if(front==-1){
            front++;
        }
        rear++;
        arr[rear]=element;
    }
    void pop(){
        if(rear==-1){
            cout<<"queue is empty ";
        }
        else{
            cout<<"popped "<<arr[rear];
            rear--;
        }
        
    }
};
int main(){
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}