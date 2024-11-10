#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    int num;
    int k;
    cout<<"enter the size of array "<<endl;
    cin>>num;
    int* arr=new int[num];
    cout<<"enter the elements ";
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"enter the smallest element number ";
    cin>>k;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<num;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    cout<<pq.top();
}