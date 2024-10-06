#include<iostream>
#include<vector>
using namespace std;
void set(vector<int>input,vector<int>output,int index,vector<vector<int>>&ans){
    if(index>=input.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    set(input,output,index+1,ans);
    //include
    int e=input[index];
    output.push_back(e);
    set(input,output,index+1,ans);

}
int main(){
    vector<int>input;
    int num;
    cout<<"enter the size of vector ";
    cin>>num;
    int element;
    for(int i=0;i<num;i++){
        cout<<"enter the element "<<i+1;
        cin>>element;
        input.push_back(element);
    }
    vector<int>output;
    vector<vector<int>>ans;
    int index=0;
    set(input,output,index,ans);
    for (const auto& subset : ans) {
        cout << "{ ";
        for (const auto& val : subset) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}