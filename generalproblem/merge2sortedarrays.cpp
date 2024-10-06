#include<iostream>
using namespace std;
int main(){
    int arr1[5]={1,3,5,7,9};
    int arr2[3]={2,4,6};
    int arr3[8];
    int i=0;
    int j=0;
    int k=0;
    while(i<5&&j<3){
        if(arr1[i]>arr2[j]){
            arr3[k]=arr2[j];
            k++;
            j++;
        }
        else{
            arr3[k]=arr1[i];
            k++;
            i++;
        }
    }
    while(i<5){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
     while(j<3){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    for(int i=0;i<8;i++){
        cout<<arr3[i]<<" ";
    }
    return 0;
}