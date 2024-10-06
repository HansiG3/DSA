#include<iostream>
using namespace std;
int sum(int arr[],int n,int s){
    int ans=0;
    if(n==0){
        return s;
    }
    if(n==1){
        return arr[0];
    }
    else{
        s=s+arr[0];
        ans=sum(arr+1,n-1,s);
    }
    return ans;

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
    int s=0;
    ans=sum(arr,n,s);
    cout<<"the sum of array is "<<ans;
}