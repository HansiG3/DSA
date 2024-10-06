#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    int num;
    cout<<"enter the number of elements";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element";
        cin>>element;
        v.push_back(element);
    }
    int flag=0;
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v.size()-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag=true;
            }
        }
        if(flag==0){
            break; //vector is already sorted because ek bhi swap nhi hua
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}