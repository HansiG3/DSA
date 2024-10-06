#include<iostream>
using namespace std;
bool search(int arr[],int n,int start,int end,int key){
    int mid=start+(end-start)/2;
    bool ans;
    if(start>end){
        return false;
    }
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        ans=search(arr,n,start,mid-1,key);
        return ans;
    }
    else{
        ans=search(arr,n,mid+1,end,key);
        return ans;
    }
}
int main(){
    int n;
    cout<<"enter the size of sorted array ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter the element "<<i+1;
        cin>>arr[i];
    }
    int key;
    cout<<"enter the key to be searched ";
    cin>>key;
    bool ans;
    int start=0;
    int end=n-1;
    ans=search(arr,n,start,end,key);
    if(ans){
        cout<<"element found ";
    }
    else{
        cout<<"not found ";
    }
}