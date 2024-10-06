#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char>st;
    string str;
    string ans;
    cout<<"enter the string "<<endl;
    cin>>str;
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }
    while(!st.empty()){
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout<<"reversed string is "<<ans;
}