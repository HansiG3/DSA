#include<iostream>
#include<string>
#include<vector>
using namespace std;
void sub(string str,int index,vector<string>output,vector<vector<string>>&ans){
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }
    //exclude
    sub(str,index+1,output,ans);
    //include
    char e=str[index];
    output.push_back(string(1,e));
    sub(str,index+1,output,ans);

}


int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    int index=0;
    vector<string>output;
    vector<vector<string>>ans;
    sub(str,index,output,ans);
    for (const auto &subset : ans) {
        cout << "{ ";
        for (const auto &val : subset) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}