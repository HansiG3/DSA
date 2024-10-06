#include<iostream>
#include<vector>
using namespace std;
bool isprime(int n){

    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cout<<"enter the number ";
    cin>>n;
    int count=0;
    vector<bool>v(n+1,true);
    v[0]=v[1]=false;
    for(int i=2;i<n+1;i++){
        if(isprime(i)){
            count++;
            for(int j=2*i;j<n+1;j=j+i){
                v[j]=0;
            }
        }
    }
    cout<<count;
}