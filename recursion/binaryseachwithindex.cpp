#include<iostream>
using namespace std;
// time complexity O(logn)
int search(int arr[],int n,int start,int end,int key){
    int mid=start+(end-start)/2;
    if(start>end){
        return -1;
    }
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return search(arr,n,start,mid-1,key);
    }
    else{
        return search(arr,n,mid+1,end,key);
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
    int ans;
    int start=0;
    int end=n-1;
    ans=search(arr,n,start,end,key);
    if(ans!=-1){
        cout<<"element found at index "<<ans;
    }
    else{
        cout<<ans;
    }
}