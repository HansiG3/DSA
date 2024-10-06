#include<iostream>
#include<string>
using namespace std;
void say(int num){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nime"};
    int digit;
    if(num==0){             
        return ;
    }
    else{
        digit=num%10;
        num=num/10;
        say(num);
        cout<<arr[digit]<<" ";

    }
}
int main(){
    int num;
    cout<<"enter the number ";
    cin>>num;
    say(num);
}