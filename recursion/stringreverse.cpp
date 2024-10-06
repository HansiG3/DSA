#include<iostream>
#include<string>
using namespace std;
string reverse(string &str,int start,int end){
    if(start>=end){
        return str;
    }
    else{
        string ans;
        char temp;
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        ans=reverse(str,start+1,end-1);
        return ans;
    }
}
int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    int start=0;
    int end=str.length()-1;
    string a;
    a=reverse(str,start,end);
    cout<<a;
    }
