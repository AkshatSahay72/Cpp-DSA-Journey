#include <bits/stdc++.h>
using namespace std;

bool isCyclicDfs(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDfs(neighbour, node, visited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

bool cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    // Create Adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // To handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDfs(i, -1, visited, adj);
            if (ans == 1)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    // Test Case 1: Simple Graph with 5 Nodes
    int V1 = 9, E1 = 8;
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {5, 7}, {6, 8}, {2, 8}, {8, 9}};
    cout << cycleDetection(edges1, V1, E1);
}