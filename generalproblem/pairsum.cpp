#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int num;
    cout<<"enter the sum";
    cin>>num;
    for(int i=0;i<5;i++){
        for(int j=i+i;j<5;j++){
            for(int k=j+1;k<5;k++){
                if(v[i]+v[j]+v[k]==num){
                cout<<v[i]<<","<<v[j]<<","<<v[k]<<endl;
            }
            }
            
        }
    }
    return 0;
}