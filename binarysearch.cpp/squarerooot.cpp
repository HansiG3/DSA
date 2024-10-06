#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int num;
    cout<<"enter the number whose square root is to be find";
    cin>>num;
    vector<int>v;
    for(int i=0;i<num;i++){
        v.push_back(i);
    }
    int start=0;
    int end=v.size()-1;
    int mid;
    int ans=0;
    while(start<=end){
        mid=start+(end-start)/2;
       
        if(v[mid]*v[mid]>num){
            end=mid-1;
        }
        else{
            ans=v[mid];
            start=mid+1;
        }
    }
    int p;
    cout<<"enter the number of precision";
    cin>>p;
    for(int i=1;i<=p;i++){
        for(int j=1;j<=9;j++){
            j=j/pow(10,i);
            ans=ans+j;
            if(ans*ans<num){
                continue;
            }
            
        }
    }
    cout<<"square root of "<<num<<": "<<ans;
    return 0;
}