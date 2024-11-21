#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void prims(vector<vector<pair<int, int>>> &adj, int num) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(num, false);

    // Starting from vertex 0
    pq.push(make_pair(0, 0));
    int mstWeight = 0;

    while (!pq.empty()) {
        pair<int, int> front = pq.top();
        pq.pop();
        int weight = front.first;
        int node = front.second;

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        mstWeight += weight;

        for (auto i : adj[node]) {
            if (!visited[i.second]) {
                pq.push(make_pair(i.first, i.second));
            }
        }
    }

    cout << "Minimum weight is " << mstWeight << endl;
}

int main() {
    int num = 5;
    vector<vector<pair<int, int>>> adj(num);

    // Add edges to the adjacency list
    adj[0].push_back(make_pair(2, 1));
    adj[1].push_back(make_pair(2, 0));
    adj[0].push_back(make_pair(3, 3));
    adj[3].push_back(make_pair(3, 0));
    adj[1].push_back(make_pair(3, 2));
    adj[2].push_back(make_pair(3, 1));
    adj[1].push_back(make_pair(1, 3));
    adj[3].push_back(make_pair(1, 1));
    adj[2].push_back(make_pair(6, 3));
    adj[3].push_back(make_pair(6, 2));
    adj[3].push_back(make_pair(4, 4));
    adj[4].push_back(make_pair(4, 3));

    // Run Prim's algorithm
    prims(adj, num);

    return 0;
}
