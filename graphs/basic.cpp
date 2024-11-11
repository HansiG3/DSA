#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>m;
    void add_edge(int u,int v,bool direction){
        //direction=0->undirected graph
        //direction=1->directed graph 
        m[u].push_back(v);
        if(direction==0){
            m[v].push_back(u);
        }
    }

    void print_adj(){
        for(auto i:m){
            cout<<i.first<<"->"<<" ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"enter the number of nodes ";
    cin>>n;
    cout<<endl;
    int edge;
    cout<<"enter the number of edges ";
    cin>>edge;
    graph g;
    int u,v;
    for(int i=0;i<edge;i++){
        cin>>u>>v;
        g.add_edge(u,v,0);
    }
    cout<<endl;
    g.print_adj();
    return 0;
}