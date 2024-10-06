#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int>v,int n,int m,int mid){
    sort(v.begin(),v.end());
    int count=1;
    int pos=v[0];
    for(int i=0;i<n;i++){
        if(v[i]-pos>=mid){
            count++;
            if(count==m){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<int>v;
    int num;
    cout<<"enter the number of stalls";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element";
        cin>>element;
        v.push_back(element);
    }
    int max=v[0];
    int min=v[0];
    int start=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>max){
            max=v[i];
        }
        if(v[i]<min){
            min=v[i];
        }
    }
    int end=max-min;
    int mid;
    int ans;
    int m;
    cout<<"enter the number of cows";
    cin>>m;
    while(start<=end){
        mid=start+(end-start)/2;
        if(ispossible(v,v.size(),m,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<ans;
}