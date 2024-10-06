#include<iostream>
using namespace std;
int power(int a,int b){
    int ans;
    if(b==0){
        return 1;
    }
    if(a==0){
        return 0;
    }
    else{
        ans=a*power(a,b-1);
        return ans;
    }
}
int main(){
    int a,b;
    cout<<"enter the number ";
    cin>>a;
    cout<<"enter the power ";
    cin>>b;
    int ans=power(a,b);
    cout<<"the answer is "<<ans;
}