#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

void adj(vector<vector<int>>& edges, vector<vector<int>>& adj_list) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}

bool iscycle(int src_node, int parent, unordered_map<int, bool>& visited, vector<vector<int>>& adj_list) {
    visited[src_node] = true;
    for (auto i : adj_list[src_node]) {
        if (!visited[i]) {
            if (iscycle(i, src_node, visited, adj_list)) {
                return true;
            }
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m; // n: number of nodes, m: number of edges
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    vector<vector<int>> adj_list(n);
    unordered_map<int, bool> visited;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    adj(edges, adj_list);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (iscycle(i, -1, visited, adj_list)) {
                cout << "Cycle detected" << endl;
                return 1;
            }
        }
    }

    cout << "No cycle detected" << endl;
    return 0;
}
