#include<iostream>
#include<vector>
using namespace std;
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
    for(int i=1;i<v.size();i++){
        int temp=v[i];
        int j=i-1;
        for(;j>=0;j--){
            if(temp<v[j]){
                v[j+1]=v[j];
            }
            else{
                break;
            }
        }
        v[j+1]=temp;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}