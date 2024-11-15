#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
    visited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour, visited, s, adj);

        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (auto &e : edges)
    {
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    // Test Case 1: Basic Directed Acyclic Graph (DAG)
    vector<pair<int, int>> edge1 = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {4, 6}};
    cout << "Test Case 1: ";
    vector<int> TCedge1 = topologicalSort(edge1);
    for (auto i : TCedge1)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test Case 2: DAG with multiple disconnected components
    vector<pair<int, int>> edge2 = {{0, 1}, {1, 2}, {3, 4}, {4, 5}};
    cout << "Test Case 2: ";
    vector<int> TCedge2 = topologicalSort(edge2);
    for (auto i : TCedge2)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test Case 3: Single node with no edges
    vector<pair<int, int>> edge3 = {};
    cout << "Test Case 3: ";
    vector<int> TCedge3 = topologicalSort(edge3);
    for (auto i : TCedge3)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test Case 4: Self-contained component in DAG
    vector<pair<int, int>> edge4 = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 6}};
    cout << "Test Case 4: ";
    vector<int> TCedge4 = topologicalSort(edge4);
    for (auto i : TCedge4)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test Case 5: Larger DAG
    vector<pair<int, int>> edge5 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5}, {5, 6}};
    cout << "Test Case 5: ";
    vector<int> TCedge5 = topologicalSort(edge5);
    for (auto i : TCedge5)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}