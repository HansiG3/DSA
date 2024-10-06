#include<iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int index=start+count;
    swap(arr[index],arr[start]);
    int i=start;
    int j=end;
    while(i<index &&j>index){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<index &&j>index){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return index;
}
void quicksort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int p=partition(arr,start,end);
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end);
}
int main(){
    int arr[5]={5,1,3,6,2};
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0])-1;
    quicksort(arr,start,end);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}