#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
int main(){
    vector<int>v;
    int num;
    cout<<"enter the size of vector";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    int start=0;
    int end=v.size()-1;

    while(start<=end){
        swap(v[start],v[end]);
        start++;
        end--;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}