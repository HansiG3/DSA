#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int k;
    cout<<"enter the value of k ";
    cin>>k;
    priority_queue<int,vector<int>,greater<int>>mini;
    int arr[6]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        int sum=0;
        for(int j=i;j<6;j++){
            sum=sum+arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    cout<<mini.top();
}