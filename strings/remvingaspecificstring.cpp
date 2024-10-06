#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    string r;
    cout<<"enter the string to be removed ";
    cin>>r;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==r[0]&&str[i+1]==r[1]&&str[i+2]==r[2]){
            str.erase(i);
            str.erase(i+1);
            str.erase(i+2);
        }
    }
}