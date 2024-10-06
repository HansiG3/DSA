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
    int element;
    for(int i=0;i<5;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    int index;
    cout<<"enter the index from where the array has to be reversed";
    cin>>index;
    int start=index+1;
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