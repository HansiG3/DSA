#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    vector<int>ans;
    int startrow=0;
    int endrow=2;
    int startcol=0;
    int endcol=2;
    while(startrow<=endrow&&startcol<=endcol){
        for(int i=startcol;i<=endcol;i++){
            ans.push_back(arr[startrow][i]);
        }
        startrow++;
        for(int i=startrow;i<=endrow;i++){
            ans.push_back(arr[i][endcol]);
        }
        endcol--;
        for(int i=endcol;i>=startcol;i--){
            ans.push_back(arr[endrow][i]);
        }
        endrow--;
        for(int i=endrow;i>=startrow;i--){
            ans.push_back(arr[i][startcol]);
        }
        startcol++;
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        return 0;
}