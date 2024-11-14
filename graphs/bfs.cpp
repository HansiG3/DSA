#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
vector<vector<int>> adj(vector<vector<int>>v){
    vector<vector<int>>adj_list(v.size());
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(v[i][j]==1){
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }
    return adj_list;
}
vector<int> bfs(vector<vector<int>>adj_list){
    map<int,bool>visited;
    queue<int>q;
    vector<int>ans;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto i:adj_list[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
int main(){
    int rows,cols;
    cout<<"enter the number of rows and columns ";
    cin>>rows>>cols;
    vector<vector<int>>matrix(rows,vector<int>(cols));
    cout<<"enter the elements ";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>v=adj(matrix);
    vector<int>ans=bfs(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}