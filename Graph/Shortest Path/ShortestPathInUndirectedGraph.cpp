#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int src, int dest){
    unordered_map<int, list<int>> adj;
    for(auto edge: edges){
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(src);
    parent[src] = -1;

    visited[src] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front]){
            if(!visited[neighbour] ){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    vector<int> ans;
    int cur = dest;

    ans.push_back(cur);

    while(cur != src){
        cur = parent[cur];
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end());
    return ans;

}


int main(){
    vector<pair<int, int>> edge1 = {{1, 2}, {2, 5}, {5, 8}, {1, 3}, {3, 8}, {1, 4}, {4, 6}, {6, 7}, {7, 8}};
    int src = 1;
    int dest = 8;
    vector<int> ans1 = shortestPath(edge1, src, dest);
    cout << "Shortest Path from " << src << " to " << dest << ": ";
    for(auto ele: ans1){
        cout << ele << " ";
    }
    cout << endl;

    // Additional test case 1
    vector<pair<int, int>> edge2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    src = 1;
    dest = 5;
    vector<int> ans2 = shortestPath(edge2, src, dest);
    cout << "Shortest Path from " << src << " to " << dest << ": ";
    for(auto ele: ans2){
        cout << ele << " ";
    }
    cout << endl;

    // Additional test case 2
    vector<pair<int, int>> edge3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
    src = 2;
    dest = 5;
    vector<int> ans3 = shortestPath(edge3, src, dest);
    cout << "Shortest Path from " << src << " to " << dest << ": ";
    for(auto ele: ans3){
        cout << ele << " ";
    }
    cout << endl;

    // Additional test case 3
    vector<pair<int, int>> edge4 = {{1, 2}, {2, 3}, {4, 5}, {3, 4}};
    src = 1;
    dest = 5;
    vector<int> ans4 = shortestPath(edge4, src, dest);
    cout << "Shortest Path from " << src << " to " << dest << ": ";
    for(auto ele: ans4){
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}