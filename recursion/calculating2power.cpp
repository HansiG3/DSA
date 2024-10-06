#include<iostream>
using namespace std;
int power(int num){
    if(num==0){
        return 1;
    }
    else{
        return(2*power(num-1));
    }
}
int main(){
    int num;
    cout<<"enter the power ";
    cin>>num;
    int ans=power(num);
    cout<<"the answer is "<<ans;
    return 0;
}