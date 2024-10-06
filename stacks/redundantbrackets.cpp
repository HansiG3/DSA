#include<iostream>
#include<stack>
using namespace std;
void redundant(string expression){
    stack<char>st;
    bool isredundant=false;
    for(int i=0;i<expression.length();i++)
     {
        
        char ch=expression[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            st.push(ch);
        }
        else if(ch==')')
            {
                isredundant=true;
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='+'||top=='-'||top=='*'||top=='/')
                    {
                        isredundant=false;
                    }
                    st.pop();
                }
                st.pop();
                if(isredundant){
                    cout<<"redundant "<<endl;
                    return;
                }
            
            }
        
    }
    if(!isredundant){
    cout<<"no redundant"<<endl;
    }
}
int main(){
    string str="(c+(a+b))";
    redundant(str);
}