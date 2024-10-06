#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int num;
    cout<<"enter the size of vector ";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    int count=0;
    for(int i=1;i<v.size();i++){
        if(v[i-1]>v[i]){
            count++;
        }
        
    }
    if(v[num-1]>v[0]){
            count++;
    }
    if(count<=1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}