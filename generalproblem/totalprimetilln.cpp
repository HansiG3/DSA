#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number ";
    cin>>n;
    int count=0;
    int flag=0;
    for(int i=2;i<n;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                flag=1;
            }
        }
        if(flag==0){
            count++;
        }
        flag=0;
    }
    cout<<"total nnumber of prime numbers till "<<n<<" "<<count;
    return 0;
}