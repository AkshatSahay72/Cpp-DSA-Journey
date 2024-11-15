#include <bits/stdc++.h>
using namespace std;

void createAdjList(const vector<pair<int, int>> &edge, unordered_map<int, list<int>> &adj)
{
    for (const auto &e : edge)
    {
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
    }
}

bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, const unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj.at(node))
    {
        if (!visited[neighbour])
        {
            if (checkCycleDfs(neighbour, visited, dfsVisited, adj))
            {
                return true;
            }
        }
        else if (dfsVisited[neighbour]) // Corrected condition
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(vector<pair<int, int>> &edge)
{
    unordered_map<int, list<int>> adj;
    createAdjList(edge, adj);

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (const auto &node : adj) // Iterate through keys of adjacency list
    {
        if (!visited[node.first])
        {
            if (checkCycleDfs(node.first, visited, dfsVisited, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // Test Case 1: Graph with a cycle
    vector<pair<int, int>> edges1 = {{1, 2}, {2, 3}, {3, 4}, {4, 2}};
    cout << "Test Case 1 (Cyclic): " << (detectCycleInDirectedGraph(edges1) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 2: Acyclic graph
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 4}};
    cout << "Test Case 2 (Acyclic): " << (detectCycleInDirectedGraph(edges2) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 3: Graph with multiple disconnected components, one cyclic
    vector<pair<int, int>> edges3 = {{1, 2}, {2, 3}, {3, 1}, {4, 5}, {5, 6}};
    cout << "Test Case 3 (Mixed): " << (detectCycleInDirectedGraph(edges3) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 4: Graph with no edges
    vector<pair<int, int>> edges4 = {};
    cout << "Test Case 4 (Empty Graph): " << (detectCycleInDirectedGraph(edges4) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 5: Single node with a self-loop
    vector<pair<int, int>> edges5 = {{1, 1}};
    cout << "Test Case 5 (Self-loop): " << (detectCycleInDirectedGraph(edges5) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 6: Larger acyclic graph
    vector<pair<int, int>> edges6 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {6, 7}, {7, 8}};
    cout << "Test Case 6 (Larger Acyclic): " << (detectCycleInDirectedGraph(edges6) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}
