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
    int k=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
        }
        else{
            swap(v[i],v[k]);
            k++;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}