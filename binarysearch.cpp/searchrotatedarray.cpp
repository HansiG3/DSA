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
    int start=0;
    int end=v.size()-1;
    int mid;
    int key;
    int flag=0;
    cout<<"enter the key to be searched";
    cin>>key;
    while(start<=end){
        mid=start+(end-start)/2;
        if(v[mid]==key){
            flag=1;
            break;
        }
        else if(v[mid]>v[start]){
            if(v[start]<=key&&key<=v[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(v[mid]<=key&&key<=v[end]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    if(flag==0){
        cout<<"key not found";
    }
    else{
        cout<<"key found at index "<<mid;
    }
}
