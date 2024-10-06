#include<iostream>
#include<vector>
using namespace std;
int minimum(vector<int>v,int size,int index){
    int min_index=index;
    for(int i=index;i<size;i++){
        if(v[i]<v[min_index]){
            min_index=i;
        }
    }
    return min_index;
}
void swap(vector<int>&v,int start,int min){
    int temp;
    temp=v[start];
    v[start]=v[min];
    v[min]=temp;
}
int main(){
    vector<int>v;
    int num;
    cout<<"enter the number of elements";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    for(int i=0;i<v.size();i++){
        int a=minimum(v,v.size(),i);
        swap(v,i,a);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}