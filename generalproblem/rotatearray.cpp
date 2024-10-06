#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1;
    int k;
    int num;
    cout<<"enter the size of vector "<<endl;
    cin>>num;
    vector<int>v2(num);
    cout<<"enter the index from where the index has to be rotated ";
    cin>>k;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element";
        cin>>element;
        v1.push_back(element);
    }
    for(int i=0;i<v1.size();i++){
        v2[(i+k)%v1.size()]=v1[i];
    }
    for(int i=0;i<num;i++){
        cout<<v2[i]<<" ";
    }
    return 0;
}