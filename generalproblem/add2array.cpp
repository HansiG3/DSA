#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    int num1,num2;
    cout<<"enter the size of the vectors ";
    cin>>num1>>num2;
    int element1,element2;
    for(int i=0;i<num1;i++){
        cout<<"enter the element of first vector ";
        cin>>element1;
        v1.push_back(element1);
    }
    for(int i=0;i<num2;i++){
        cout<<"enter the element of second vector ";
        cin>>element2;
        v2.push_back(element2);
    }
    int i=v1.size()-1;
    int j=v2.size()-1;
    int sum=0;
    int carry=0;
    while(i>=0&&j>=0){
        sum=v1[i]+v2[j]+carry;
        carry=sum/10;
        sum=sum%10;
        v3.push_back(sum);
        i--;
        j--;
    }
    while(i>=0){
        sum=v1[i]+carry;
        carry=sum/10;
        sum=sum%10;
        v3.push_back(sum);
        i--;
    }
    while(j>=0){
        sum=0;
        sum=v1[j]+carry;
        carry=sum/10;
        sum=sum%10;
        v3.push_back(sum);
        j--;
    }
    while(carry!=0){
        sum=carry;
        carry=sum/10;
        sum=sum%10;
        v3.push_back(sum);
    }
    for(int i=v3.size()-1;i>=0;i--){
        cout<<v3[i]<<" ";
    }
    return 0;
}