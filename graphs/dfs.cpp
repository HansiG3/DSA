#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
void dfs(int node, unordered_map<int, bool> &visited, vector<vector<int>>&adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;
    // for every connected node k liye recursive call
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int> > depthFirstSearch(int V, int E, vector< vector<int> > edges)
{
    // prepare adiList
    vector<vector<int>>adj;
    //there are 2 columns im edges so we extract u and v 
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int> > ans;
    unordered_map<int, bool> visited;
    //graph is disconnected thereforw we used a for loop
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}