#include<iostream>
using namespace std;
int stairs(int num){
    int a;
    if(num<0){
        return 0;
    }
    if(num==0){
        return 1;
    }
    else{
        a=stairs(num-1)+stairs(num-2);
    }
    return a;
}
int main(){
    int num;
    int ans;
    cout<<"enter the number of stairs ";
    cin>>num;
    ans=stairs(num);
    cout<<" number of ways "<<ans;
    return 0;
}