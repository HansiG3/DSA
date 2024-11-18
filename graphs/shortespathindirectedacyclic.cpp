#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;
class graph{
    public:
    void add_edge(int u,int v,int weight,vector<vector<pair<int,int>>>&adj_list){
        pair<int,int>p=make_pair(v,weight);
        adj_list[u].push_back(p);
    }
    void dfs(int src,unordered_map<int,bool>&visited,stack<int>&s,vector<vector<pair<int,int>>>&adj_list){
        visited[src]=true;
        for(auto i:adj_list[src]){
            if(!visited[i.first]){
                dfs(i.first,visited,s,adj_list);
            }
        }
        s.push(src);
    }
    void shortest_path(vector<int>&distance,int src_node,stack<int>&s,vector<vector<pair<int,int>>>&adj_list){
        for(int i=0;i<6;i++){
            distance[i]=INT_MAX;
        }
        distance[src_node]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(distance[top]!=INT_MAX){
                for(auto i:adj_list[top]){
                    if(distance[top]+i.second<distance[i.first]){
                        distance[i.first]=distance[top]+i.second;
                    }
                }
            }
        }
    }
    
};
int main(){
    graph g;
    vector<vector<pair<int,int>>>adj_list(6);
    g.add_edge(0,1,5,adj_list);
    g.add_edge(0,2,3,adj_list);
    g.add_edge(1,2,2,adj_list);
    g.add_edge(1,3,6,adj_list);
    g.add_edge(2,3,7,adj_list);
    g.add_edge(2,4,4,adj_list);
    g.add_edge(2,5,2,adj_list);
    g.add_edge(2,4,4,adj_list);
    g.add_edge(3,4,-1,adj_list);
    g.add_edge(4,5,-2,adj_list);

    unordered_map<int,bool>visited;
    stack<int>s;
    int n=6;
    for(int i=0;i<6;i++){
        if(!visited[i]){
            g.dfs(i,visited,s,adj_list);
        }
    }
    int src_node=1; //iske comparison mai we are seeing shortest distance like 1 se 2 ,1 se 3 so on
    vector<int>distance(n);
    g.shortest_path(distance,src_node,s,adj_list);

    cout<<endl;
    for(int i=0;i<distance.size();i++){
        cout<<distance[i]<<" ";
    }
}