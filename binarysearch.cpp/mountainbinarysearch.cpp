#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int num;
    cout<<"enter the size of vector";
    cin>>num;
    int element;
    if(num>=3){
        for(int i=0;i<num;i++){
            cout<<"enter the elelemt of a mountain vector "<<i+1<<" ";
            cin>>element;
            v.push_back(element);
        }
    }
    else{
        cout<<"cant display invalid size"<<endl;
        return 0;
    }
    int start=0;
    int end=v.size()-1;
    int mid;
    int max=v[start];
    while(start<=end){
        mid=start+(end-start)/2;
        if(v[mid]>max){
            max=v[mid];
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<"maximum element"<<max;
    return 0;
}
