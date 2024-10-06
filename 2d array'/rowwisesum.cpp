#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    int i,j;
    cout<<"enter the elements ";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    int sum=0;
    int max=0;
    int index=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum=sum+arr[i][j];
            if(sum>max){
                max=sum;
                index=i;
            }
        }
        cout<<"sum of "<<i+1<<" row "<<sum<<endl;
        sum=0;
    }
    cout<<"max sum is "<<max<<" of row "<<index;
    return 0;
}