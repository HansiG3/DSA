#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    int i=0;
    int len=str.length();
    while(len!=0){
        for(int i=0;i<str.length()-1;i++){
            if(str[i]==str[i+1]){
                str.erase(str.begin()+i,str.begin()+i+2);
                len=str.length();
            }
        }
    }
    cout<<str;
    return 0;
}