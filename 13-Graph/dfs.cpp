#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> DFS(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    // Test Case 1: Simple Graph with 5 Nodes
    int V1 = 5, E1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    cout << "Test Case 1: ";
    for (auto component : DFS(V1, E1, edges1)) {
        for (int node : component) cout << node << " ";
        cout << "| ";
    }
    cout << endl;

    // Test Case 2: Graph with Multiple Components
    int V2 = 6, E2 = 3;
    vector<vector<int>> edges2 = {{0, 1}, {2, 3}, {4, 5}};
    cout << "Test Case 2: ";
    for (auto component : DFS(V2, E2, edges2)) {
        for (int node : component) cout << node << " ";
        cout << "| ";
    }
    cout << endl;

    // Test Case 3: Complete Graph
    int V3 = 4, E3 = 6;
    vector<vector<int>> edges3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    cout << "Test Case 3: ";
    for (auto component : DFS(V3, E3, edges3)) {
        for (int node : component) cout << node << " ";
        cout << "| ";
    }
    cout << endl;

    // Test Case 4: Single Node
    int V4 = 1, E4 = 0;
    vector<vector<int>> edges4 = {};
    cout << "Test Case 4: ";
    for (auto component : DFS(V4, E4, edges4)) {
        for (int node : component) cout << node << " ";
        cout << "| ";
    }
    cout << endl;

    // Test Case 5: Disconnected Graph with Isolated Nodes
    int V5 = 7, E5 = 3;
    vector<vector<int>> edges5 = {{0, 1}, {0, 2}, {3, 4}};
    cout << "Test Case 5: ";
    for (auto component : DFS(V5, E5, edges5)) {
        for (int node : component) cout << node << " ";
        cout << "| ";
    }
    cout << endl;

    return 0;
}
