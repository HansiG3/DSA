#include<iostream>
#include<stack>
using namespace std;
class stacks{
    public:
    int size;
    int *arr;
    int top1;
    int top2;
    stacks(int size){
        this->size=size;
        int *arr=new int[size];
        int top1=-1;
        int top2=size;
    }
    void push1(int element){
        if(top2-top1>1){
            top1++;
            arr[top1]=element;
        }
        else{
            cout<<"stack overflow "<<endl;
        }
    }
    void push2(int element){
        if(top2-top1>1){
            top2--;
            arr[top2]=element;
        }
        else{
            cout<<"stack overflow "<<endl;
        }
    }
    void pop1(){
        if(top1>=0){
            cout<<arr[top1];
            top1--;
        }
        else{
            cout<<"stack underflow "<<endl;
        }
    }
    void pop2(){
        if(top2<size){
            cout<<arr[top2];
            top2++;
        }
        else{
            cout<<"stack underflow "<<endl;
        }
    }
};