#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool issafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& input) {
    if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && input[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(vector<vector<int>>& input, int n, int srcx, int srcy, vector<vector<int>>& visited, string path, vector<string>& ans) {
    if(input[0][0] == 0) {
        return;
    }
    if(srcx == n - 1 && srcy == n - 1) {
        ans.push_back(path);
        return;
    }
    visited[srcx][srcy] = 1;
    // 4 choices right, left, down, up
    // left
    int x = srcx;
    int y = srcy - 1;
    if(issafe(x, y, n, visited, input)) {
        path.push_back('L');
        solve(input, n, x, y, visited, path, ans);
        path.pop_back();
    }
    // right
    x = srcx;
    y = srcy + 1;
    if(issafe(x, y, n, visited, input)) {
        path.push_back('R');
        solve(input, n, x, y, visited, path, ans);
        path.pop_back();
    }
    // down
    x = srcx + 1;
    y = srcy;
    if(issafe(x, y, n, visited, input)) {
        path.push_back('D');
        solve(input, n, x, y, visited, path, ans);
        path.pop_back();
    }
    // up
    x = srcx - 1;
    y = srcy;
    if(issafe(x, y, n, visited, input)) {
        path.push_back('U');
        solve(input, n, x, y, visited, path, ans);
        path.pop_back();
    }
    visited[srcx][srcy] = 0;
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    
    vector<vector<int>> input(m, vector<int>(n));
    cout << "Enter the maze elements: " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    vector<vector<int>> visited(m, vector<int>(n, 0));
    
    string path = "";
    int srcx = 0, srcy = 0;
    vector<string> ans;
    
    solve(input, n, srcx, srcy, visited, path, ans);
    
    cout << "The paths are:" << endl;
    for (const auto& p : ans) {
        cout << p << endl;
    }
    
    return 0;
}
