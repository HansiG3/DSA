#include<iostream>
#include<vector>
using namespace std;
bool ispossible(vector<int>v,int n,int m,int mid){
    int count=1;
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(sum+v[i]<=mid){
            sum=sum+v[i];
        }
        else{
            count++;
            if(count>m||v[i]>mid){
                return false;
            }
            else{
                sum=0;
                sum=sum+v[i];
            }
        }
    }
    return true;
}
int main(){
    vector<int>v;
    int num;
    cout<<"enter the number of elements";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    int start=0;
    int sum=0;
    int mid;
    int ans;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    int end=sum;
    int m;
    cout<<"enter the number of painters";
    cin>>m;
    while(start<end){
        mid=start+(end-start)/2;
        if(ispossible(v,v.size(),m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans;
}
