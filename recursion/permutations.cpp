#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>input,int index,vector<vector<int>>&ans){
    if(index>=input.size()){
        ans.push_back(input);
        return;
    }
    for(int j=index;j<input.size();j++){
        swap(input[index],input[j]);
        solve(input,index+1,ans);
        swap(input[index],input[j]);
    }
}
int main(){
    vector<int>input;
    vector<vector<int>>ans;
    int index=0;
    int num;
    cout<<"enter the size of vector ";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        input.push_back(element);
    }
    solve(input,index,ans);
    for (const auto& subset : ans) {
        cout << "{ ";
        for (const auto& val : subset) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}