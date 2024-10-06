#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int i,j;
    for(i=0;i<3;i++){
        for(j=i;j<3;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(i=0;i<3;i++){
        for(j=2;j>=0;j--){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}