#include<iostream>
#include<stack>
using namespace std;

void sorted(stack<int>& s, int top) {
    if (s.empty() || s.top() < top) {
        s.push(top);
    } else {
        int n = s.top();
        s.pop();
        sorted(s, top);
        s.push(n);
    }
}

void sortstack(stack<int>& s) {
    if (s.empty()) {
        return;
    } else {
        int top = s.top();
        s.pop();
        sortstack(s);
        sorted(s, top);
    }
}

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(43);
    s.push(8);
    sortstack(s);
    print(s);

    return 0;
}
