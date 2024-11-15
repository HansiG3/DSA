#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void adj(vector<vector<int>>& edges, vector<vector<int>>& adj_list) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj_list[u].push_back(v);
    }
}
bool iscycle(int node,vector<vector<int>>&adj_list,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfs_visited){
    visited[node]=true;
    dfs_visited[node]=true;
    for(auto i:adj_list[node]){
        if(!visited[i]){
            bool ans=iscycle(i,adj_list,visited,dfs_visited);
            if(ans==1){
                return true;
            }
        }
        else if(dfs_visited[i]==true){
            return true;
        }
    }
    dfs_visited[node]=false;
    return false;
}
int main(){
    int n, m; // n: number of nodes, m: number of edges
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    vector<vector<int>> adj_list(n);
    unordered_map<int, bool> visited;
    unordered_map<int,bool>dfs_visited;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    adj(edges, adj_list);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (iscycle(i,adj_list,visited,dfs_visited)) {
                cout << "Cycle detected" << endl;
                return 1;
            }
        }
    }

    cout << "No cycle detected" << endl;
    return 0;
}

