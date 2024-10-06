#include<iostream>
using namespace std;
//time complexity O(n)
int fibo(int num){
    int ans;
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    else{
        
        ans=fibo(num-1)+fibo(num-2);
    }
    return ans;
}
int main(){
    int num;
    cout<<"enter the limit ";
    cin>>num;
    int a;
    a=fibo(num);
    cout<<"annswer is "<<a;
}