#include<iostream>
using namespace std;
int main(){
    int i,j;
    int arr[3][3];
    cout<<"enter the element ";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int start=0;
    int end=(3*3)-1;
    int mid;
    int element;
    cout<<"enter the element to be searched ";
    cin>>element;
    while(start<=end){
        mid=start+(end-start)/2;
        int val=arr[mid/3][mid%3];
        if(element==val){    //arr[mid/col][mid%col} 
            cout<<"element found";
            break;
        }
        else if(element>val){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return 0;
}