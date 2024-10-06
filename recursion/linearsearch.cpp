#include<iostream>
using namespace std;
bool isfound(int arr[],int n,int key){
    bool ans;
    if(n==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        ans=isfound(arr+1,n-1,key);
        return ans;
    }

}
int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int *arr =new int[n];
    cout<<"enter the elements ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter the element to be searched ";
    cin>>key;
    bool ans;
    ans=isfound(arr,n,key);
    if(ans){
        cout<<"key found ";
    }
    else{
        cout<<"key not found ";
    }
    return 0;
}