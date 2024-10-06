#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"enter the string";
    getline(cin,str);
    string result;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            result+="@40";
        }
        else{
            result+=str[i];
        }
        i++;
    }
    cout<<result;
    return 0;
}