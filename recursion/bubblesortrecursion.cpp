#include<iostream>
using namespace std;
void tosort(int arr[],int n){
    if(n==0||n==1){
        return ;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        tosort(arr,n-1);
    }
}
int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter the elements ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    tosort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
