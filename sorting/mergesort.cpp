#include<iostream>
using namespace std;
// time complexity O(nlogn)
void merge(int arr[],int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;

    int *first=new int[len1];
    int *second=new int[len2];
    for(int i=0;i<len1;i++){
        first[i]=arr[start+i];
    }
    for(int i=0;i<len2;i++){
        second[i]=arr[mid+1+i];
    }
    int index1=0;
    int index2=0;
    int index3=start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[index3]=first[index1];
            index3++;
            index1++;
        }
        else{
            arr[index3]=second[index2];
            index3++;
            index2++;
        }
    }
    while(index1<len1){
        arr[index3]=first[index1];
        index3++;
        index1++;
    }
    while(index2<len2){
        arr[index3]=second[index2];
        index3++;
        index2++;
    }
}
void mergesort(int arr[],int start,int end){
    int mid=start+(end-start)/2;
    if(start>=end){
        return;
    }
    else{
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
    }
    merge(arr,start,end);
}
int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter the element "<<i+1;
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    mergesort(arr,start,end);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}