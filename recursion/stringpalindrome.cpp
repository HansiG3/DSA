#include<iostream>
using namespace std;
bool ispalindrome(string str,int start,int end){
    bool a;
    if(start>=end){
        return true;
    }
    if(str[start]!=str[end]){
        return false;
    }
    else{
        a=ispalindrome(str,start+1,end-1);
        return a;
    }
}
int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    int start=0;
    int end=str.length()-1;
    bool ans;
    ans=ispalindrome(str,start,end);
    if(ans){
        cout<<"it is a palindrome ";
    }
    else{
        cout<<"not a palindrome ";
    }

}