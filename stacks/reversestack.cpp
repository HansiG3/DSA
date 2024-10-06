#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
    } else {
        int top = s.top();
        s.pop();
        insertAtBottom(s, element);
        s.push(top);
    }
}

void reversestack(stack<int>& s) {
    if(s.empty()){
        return;
    }
    else{
        int top=s.top();
        s.pop();
        reversestack(s);
        insertAtBottom(s,top);
    }
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    reversestack(s);

    printStack(s);

    return 0;
}
