#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
void adj(vector<vector<int>>edges,vector<vector<int>>&adj_list){
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}
void bfs(int src_node,vector<vector<int>>&adj_list,unordered_map<int,bool>&visited,unordered_map<int,int>&parent){
    queue<int>q;
    q.push(src_node);
    visited[src_node]=1;
    parent[src_node]=-1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj_list[front]){
            visited[front]=true;
            parent[i]=front;
            q.push(i);
        }
    }
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
    unordered_map<int,int>parent;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    adj(edges, adj_list);
    int src_node;
    int destination;
    cout<<"enter the source node and destination node";
    cin>>src_node>>destination;
    int currentnode=destination;
    vector<int>ans;
    ans.push_back(currentnode);
    while(currentnode!=src_node){
        currentnode=parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}