#include<iostream>
#include<vector>
using namespace std;
class heap{
    public:
    vector<int>v;
    heap(){
        v.push_back(-1);
    }
    void insert(int val){
        //insertion time complexity o(logn)
        v.push_back(val);
        int index=v.size()-1;
        while(index>1){
            int parent=index/2;
            if(v[index]>v[parent]){
                swap(v[parent],v[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromheap(){
        if(v.size()==0){
            cout<<"nothing to delete ";
        }
        v[1]=v[v.size()-1];
        v.pop_back();
        int i=1;
        while(i<v.size()){
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(leftindex<v.size() && v[i]<v[leftindex]){
                swap(v[i],v[leftindex]);
                i=leftindex;
            }
            else if(rightindex<v.size() && v[i]<v[leftindex]){
                swap(v[i],v[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
};
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout<<endl;
    h.deletefromheap();
    h.deletefromheap();
    h.deletefromheap();
    h.print();
}