#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num;
    cout<<"enter number";
    cin>>num;
    int bit=0;
    int sum=0;
    int i=0;
    while(num!=0){
        bit=num&1;
        sum=sum+bit*pow(10,i);
        num>>1;
        i++;
    }
    cout<<sum;
}