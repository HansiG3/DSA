#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    //MAX HEAP
    priority_queue<int>pq;
    pq.push(2);
    pq.push(5);
    pq.push(7);
    pq.push(6);
    cout<<pq.top()<<" ";
    pq.pop();
    if(!pq.empty()){
        cout<<"not empty";
    }
    else{
        cout<<"empty";
    }

    //MIN HEAP  
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(3);
    minheap.push(10);
    minheap.push(6);
    minheap.push(1);
    cout<<minheap.top()<<" ";
    minheap.pop();
    if(!minheap.empty()){
        cout<<"not empty";
    }
    else{
        cout<<"empty";
    }
}