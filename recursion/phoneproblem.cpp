#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve(string input,string output,int index,vector<string>&ans,string mapping[]){
    if(index>=input.length()){
        ans.push_back(output);
        return;
    }
    int number=input[index]-'0'; //-'0' to get integer value of it
    string value=mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        solve(input,output,index+1,ans,mapping);
        output.pop_back();
    }
}
int main(){
    vector<string>ans;
    string output;
    string input;
    cout<<"enter the number from 2-9 ";
    cin>>input;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index=0;
    solve(input,output,index,ans,mapping);
    for (const auto &subset : ans) {
        cout << subset << " ";
    }
    cout << endl;
    return 0;
}
    