#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main(){
    map<char,int>m;
    string str;
    cout<<"enter the string ";
    cin>>str;
    int len=str.length();
    int count=0;
    for(int i=0;i<len;i++){
        str[i]=tolower(str[i]);
        for(int j=0;j<len;j++){
            str[j]=tolower(str[j]);
            if(str[i]==str[j]){
                count++;
            }
        }
        if(m.find(str[i])==m.end()){
            m.insert(pair<char,int>(str[i],count));
        }
        count=0;
    }
    int max=0;
    map<char,int>::iterator it=m.begin();
    char temp;
    for(it;it!=m.end();it++){
        if(max<it->second){
            max=it->second;
            temp=it->first;
        }
    }
    int c=0;
    vector<char>v;
    for(it;it!=m.end();it++){
        if(max==it->second){
            v.push_back(it->first);
            c++;
        }
    }
    char ans;
    if(c>1){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(v[i]>v[j]){
                    ans=v[i];
                }
                else{
                    ans=v[j];
                }
            }
        }
        cout<<"max occurence is of "<<ans<<" "<<max;
    }
    else{
        cout<<"max occurence is of "<<temp<<" "<<max;
    }
    return 0;
}
    