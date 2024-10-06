#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    int num,element;
    cout<<"enter the size of vector";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    sort(v.begin(),v.end());
    int start=0;
    int end=v.size()-1;
    int mid;
    int key;
    cout<<"enter whose index are to be printed";
    cin>>key;
    int ans=0;
    int count=0;
    while(start<=end){
        mid=start+(end-start)/2;
        if(v[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(v[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<"first occurrence"<<ans<<endl;
    start=0;
    end=v.size()-1;
    int last=0;
    while(start<=end){
        mid=start+(end-start)/2;
        if(v[mid]==key){
            last=mid;
            start=mid+1;;
        }
        else if(v[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<"last occurrence"<<last<<endl;
    count=(last-ans)+1;
    cout<<"total number of times "<<key<<"occurred"<<count;
    return 0;
}