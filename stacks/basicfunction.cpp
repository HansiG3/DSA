#include<iostream>
#include<stack>
using namespace std;
class stacks{
    public:
    int *arr;
    int top;
    int size;
    stacks(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow "<<endl;
        }
    }
    void pop(){
        if(top<0){
            cout<<"stack undeflow "<<endl;
        }
        else{
            top--;
        }
    }
    void peek(){
        if(top>=0){
            cout<<"top element is"<<arr[top]<<endl;
        }
        else{
            cout<<"stack is empty "<<endl;
        }
        
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    stacks st(5);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.peek();
    st.pop();
    st.pop();
    st.peek();
    if(st.isempty()){
        cout<<"empty "<<endl;
    }
    else{
        cout<<"not empty "<<endl;
    }
    }
