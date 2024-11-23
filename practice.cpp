#include<bits/stdc++.h>
using namespace std;

vector<int> shortest(vector<int> adj[], int v, int src, int dest){
    vector<int> ans;
    vector<bool> visited(v, 0);
    vector<int> parent(v, -1);

    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto j: adj[front]){
            if(!visited[j]){
                q.push(j);
                parent[j] = front;
                visited[j] = true;
            }
        }
    }

        

    int cur = dest;

    while(cur!=-1){

        ans.push_back(cur);
        cur = parent[cur];
    }

    if (ans.back() != src) {
        return {}; // Return empty vector if no path exists
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int V = 9;
    vector<int> edge1[V] = {{1, 2}, {2, 5}, {5, 8}, {1, 3}, {3, 8u}, {1, 4}, {4, 6}, {6, 7}, {7, 8}};
    vector<int> adj[V];
    for (int i = 0; i < V; i++) {
        if (!edge1[i].empty()) {
            int u = edge1[i][0];
            int v = edge1[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Assuming undirected graph
        }
    }
    int src = 1;
    int dest = 8;
    vector<int> ans1 = shortest(adj, V, src, dest);
    cout << "Shortest Path from " << src << " to " << dest << ": ";
    for (auto ele : ans1)
    {
        cout << ele << " ";
    }
    cout << endl;
}