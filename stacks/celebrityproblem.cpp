#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>>& v, int a, int b) {
    return v[a][b] == 1;
}

int celeb(vector<vector<int>>& v, int size) {
    stack<int> s;
    for (int i = 0; i < size; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(v, a, b)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int celebrity = s.top();

    // Verify the potential celebrity
    int zerocount = 0;
    for (int i = 0; i < size; i++) {
        if (v[celebrity][i] == 0) {
            zerocount++;
        }
    }
    bool rowcheck = false;
    if (zerocount == size) {
        rowcheck = true;
    }

    int onecount = 0;
    for (int i = 0; i < size; i++) {
        if (v[i][celebrity] == 1) {
            onecount++;
        }
    }
    bool colcheck = false;
    if (onecount == size - 1) { // All should know the celebrity except the celebrity itself
        colcheck = true;
    }

    if (rowcheck == true && colcheck == true) {
        return celebrity;
    }
    return -1;
}

int main() {
    int row, col;
    cout << "Enter the size of matrix (should be square matrix): ";
    cin >> row >> col;

    if (row != col) {
        cout << "Matrix should be square" << endl;
        return -1;
    }

    vector<vector<int>> v(row, vector<int>(col));
    cout << "Enter the elements: ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
        }
    }

    int ans = celeb(v, row);
    cout << "Celebrity ID: " << ans << endl;

    return 0;
}
