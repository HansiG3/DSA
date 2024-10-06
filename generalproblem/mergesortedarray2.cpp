#include<iostream>
using namespace std;
int main(){
    //same hi array mai karna hain abh no new array
    int arr1[6]={1,2,3};
    int arr2[3]={2,4,6};
    for(int i=0;i<3;i++){
        arr1[3+i]=arr2[i];
    }
    for(int i=0;i<6;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}