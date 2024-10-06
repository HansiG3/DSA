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
        cout<<"enter the elelemt of a roatated sorted  vector "<<i+1<<" ";
        cin>>element;
        v.push_back(element);
    }
    int start=0;
    int end=v.size()-1;
    int mid;
    int min=v[start];
    while(start<=end){
        mid=start+(end-start)/2;
        if(v[mid]<min){
            min=v[mid];
            end=mid-1;;
        }
        else{
            start=mid+1;
        }
    }
    
    cout<<"minimum element is "<<min<<"present at index "<<start;
    return 0;
}
