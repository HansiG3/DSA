#include<iostream>
#include<vector>
using namespace std;
bool ispossible(vector<int>v,int n,int m,int mid){
    int count=1;
    int pagesum=0;
    for(int i=0;i<n;i++){
        if(pagesum+v[i]<=mid){
            pagesum=pagesum+v[i];
        }
        else{
            count++;
            if(count>m||v[i]>mid){
                return false;
            }
            pagesum=0;
            pagesum=pagesum+v[i];
        }
    }
    return true;
}
int main(){
    vector<int>v;
    int num;
    cout<<"enter the number of elements in a vector";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the number of pages of book "<<i+1;
        cin>>element;
        v.push_back(element);
    }
    int start=0;
    int sum=0;
    int mid;
    for(int i=0;i<v.size();i++){
        sum=sum+v[i];
    }
    int end=sum;
    int ans=-1;
    int mid;
    int m;
    cout<<"enter the number of students";
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
    return ans;
    }
