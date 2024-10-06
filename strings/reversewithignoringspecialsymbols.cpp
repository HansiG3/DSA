#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    string temp;
    cout<<"enter the string ";
    getline(cin,str);
    int i=0;
    while(str[i]!='\0'){
        str[i]=tolower(str[i]);
        if(str[i]>='a'&&str[i]<='z'||str[i]>='0'&&str[i]<='9'){
            temp.push_back(str[i]);
        }
        i++;
    }
    int start=0;
    int end=temp.length()-1;
    int flag=1;
    while(start<end){
        if(temp[start]!=temp[end]){
            flag=0;
            break;
        }
        start++;
        end--;
    }
    if(flag==1){
        cout<<"palindrome";
    }
    else{
        cout<<"not a palindrome";
    }
}
