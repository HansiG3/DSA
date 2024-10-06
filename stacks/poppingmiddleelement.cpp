#include<iostream>
#include<stack>
using namespace std;
void popmiddle(stack<int>&st,int count,int size){
    if(count==size/2){
        st.pop();
        return;
    }
    else{
        int num=st.top();
        st.pop();
        popmiddle(st,count+1,size);
        st.push(num);
    }
}
void printstack(stack<int>st){
    stack<int>temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
}
int main(){
    stack<int>st;
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    int count=0;
    popmiddle(st,count,st.size());
    printstack(st);
}