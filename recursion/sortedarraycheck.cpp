#include<iostream>
using namespace std;
bool issorted(int arr[],int n){
    bool ans;
    if(n==0||n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        ans=issorted(arr+1,n-1);
        return ans;
    }
}
int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter the element "<<i+1<<" ";
        cin>>arr[i];
    }
    int ans;
    ans=issorted(arr,n);
    cout<<ans;
    }