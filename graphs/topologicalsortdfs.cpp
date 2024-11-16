#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;
void adj(vector<vector<int>>& edges, vector<vector<int>>& adj_list) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj_list[u].push_back(v);
    }
}
void toposort(int node,vector<vector<int>>& adj_list,unordered_map<int,bool>&visited,stack<int>&s){
    visited[node]=true;
    for(auto i:adj_list[node]){
        if(!visited[i]){
            toposort(i,adj_list,visited,s);
        }
    }
    s.push(node);
}
int main(){
    int n, m; // n: number of nodes, m: number of edges
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    vector<vector<int>> adj_list(n+1);
    unordered_map<int, bool> visited;
    stack<int>s;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    adj(edges, adj_list);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            toposort(i,adj_list,visited,s);
        }
        }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}