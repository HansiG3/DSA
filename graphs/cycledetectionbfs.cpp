#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
//undirected graph
// time complexity is same as that of bfs i.e O(n)
void adj(vector<vector<int>>edges,vector<vector<int>>&adj_list){
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}
bool iscycle(unordered_map<int,int>parent,vector<vector<int>>adj_list,int src_node,unordered_map<int,bool>&visited){
    queue<int>q;
    q.push(src_node);
    parent[src_node]=-1;
    visited[src_node]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj_list[front]){
            if(visited[i]==true && i!=parent[front]){
                return true;
            }
            else if(visited[i]==false){
                q.push(i);
                visited[i]=true;
                parent[i]=front;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<int>>edges;
    unordered_map<int,int>parent;
    vector<vector<int>>adj_list;
    unordered_map<int,bool>visited;
    int n;
    cout<<"enter the number of nodes ";
    cin>>n;
    adj(edges,adj_list);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=iscycle(parent,adj_list,i,visited);
            if(ans==true){
                return 1;
            }
        }
    }
    return 0;
}