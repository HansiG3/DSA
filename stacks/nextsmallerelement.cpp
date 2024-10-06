#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> smaller(vector<int> v, int size) {
    stack<int> s;
    vector<int> ans(size);

    for (int i = size - 1; i >= 0; i--) {  // Traverse from right to left
        while (!s.empty() && s.top() >= v[i]) {
            s.pop();  // Pop elements that are greater than or equal to the current element
        }
        
        if (s.empty()) {
            ans[i] = -1;  // If stack is empty, no smaller element exists to the right
        } else {
            ans[i] = s.top();  // The top element is the next smaller element
        }

        s.push(v[i]);  // Push the current element onto the stack
    }
    
    return ans;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

int main() {
    vector<int> v = {2, 1, 5, 7};
    vector<int> ans = smaller(v, 4);
    print(ans);
    return 0;
}
