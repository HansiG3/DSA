#include<iostream>
using namespace std;
int count(int num){
    if(num==0){
        return 0;
    }
    else{
        cout<<num<<endl;
        num=count(num-1);
    }

}
int main(){
    int num;
    cout<<"enter the number ";
    cin>>num;
    count(num);
    return 0;
}