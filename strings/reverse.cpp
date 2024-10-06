#include<iostream>
#include<string>
#include<vector>
using namespace std;
void swap(char &a,char &b){
    char temp=a;
    a=b;
    b=temp;
}
int main(){
    vector<char>v1;
    int num;
    cout<<"enter the size of character vector";
    cin>>num;
    char ch;
    for(int i=0;i<num;i++){
        cout<<"enter the character "<<i+1;
        cin>>ch;
        v1.push_back(ch);
    }
    vector<char>v2;
    v2=v1;
    int start=0;
    int end=v1.size()-1;
    while(start<end){
        swap(v1[start],v1[end]);
        start++;
        end--;
    }
    if(v1==v2){
        cout<<"it is a palindrome";
    }
    else{
        cout<<"not a palindrome";
    }
    return 0;
}