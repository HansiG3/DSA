#include <iostream>
#include <stack>
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

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(1);

    insertAtBottom(s, 7); // Insert element at the bottom
    
    cout << "Stack elements from top to bottom:" << endl;
    printStack(s); // Print the stack
    
    return 0;
}
