#include<iostream>
int fact(int num){
    // time complexity O(2^n)
    int a;
    if(num==0){
        return 1;
    }
    else{
        a=num*fact(num-1);
    }
    return a;
}
using namespace std;
int main(){
    int ans;
    int num;
    cout<<"enter the number ";
    cin>>num;
    ans=fact(num);
    cout<<"the factorial is "<<ans;
    return 0;
}