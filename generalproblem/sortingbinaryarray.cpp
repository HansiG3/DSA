#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    int i=0;
    int j=v.size()-1;
    while(i<=j){
        if(i<j&&v[i]==0){
            i++;
        }
        else{
            v[i]=v[i]^1;
            i++;
        }
        if(i<j&&v[j]==1){
            j--;
        }
        else{
            v[j]=v[j]^1;
        }

    }
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }

}