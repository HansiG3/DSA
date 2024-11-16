#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
void adj(vector<vector<int>>edges,vector<vector<int>>&adj_list){
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj_list[u].push_back(v);
    }
}
int main(){
    int n;
    cout<<"enter the number of nodes";
    cin>>n;
    int e;
    cout<<"enter the number of edges ";
    cin>>e;
    vector<vector<int>>edges(e,vector<int>(2));
    cout<<"enter the edges ";
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>adj_list(n+1);
    adj(edges,adj_list);
    queue<int>q;

    //forming the indegree array
    vector<int>indegree(n+1);
    for(auto i:adj_list){
        for(auto j:i) {
            indegree[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj_list[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}