#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<pair<int, int>>> adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> shortestPath(unordered_map<int, list<pair<int, int>>> adj, int src)
{

    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adj);
        }
    }

    vector<int> dist(adj.size(), INT_MAX);

    dist[src] = 0;

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (dist[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                if (dist[top] + i.second < dist[i.first])
                {
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }

    return dist;
}

int main()
{
    // Test graph adjacency list
    unordered_map<int, list<pair<int, int>>> adj1 = {
        {0, {{1, 5}, {2, 3}}},
        {1, {{2, 2}, {3, 6}}},
        {2, {{3, 7}, {4, 4}, {5, 2}}},
        {3, {{4, -1}}},
        {4, {{5, -2}}},
        {5, {{6, 1}}},
        {6, {{7, 8}, {8, 3}}}};

    // Test Case 1
    cout << "Test Case 1: Source Node = 0\n";
    vector<int> sp1 = shortestPath(adj1, 0);
    for (auto ele : sp1)
    {
        if (ele == INT_MAX)
            cout << "INF ";
        else
            cout << ele << " ";
    }
    cout << "\n\n";

    // Test Case 2
    cout << "Test Case 2: Source Node = 1\n";
    vector<int> sp2 = shortestPath(adj1, 1);
    for (auto ele : sp2)
    {
        if (ele == INT_MAX)
            cout << "INF ";
        else
            cout << ele << " ";
    }
    cout << "\n\n";

    // Test Case 3
    cout << "Test Case 3: Source Node = 2\n";
    vector<int> sp3 = shortestPath(adj1, 2);
    for (auto ele : sp3)
    {
        if (ele == INT_MAX)
            cout << "INF ";
        else
            cout << ele << " ";
    }
    cout << "\n\n";

    // Test Case 4
    cout << "Test Case 4: Source Node = 3\n";
    vector<int> sp4 = shortestPath(adj1, 3);
    for (auto ele : sp4)
    {
        if (ele == INT_MAX)
            cout << "INF ";
        else
            cout << ele << " ";
    }
    cout << "\n\n";

    // Test Case 5
    cout << "Test Case 5: Source Node = 4\n";
    vector<int> sp5 = shortestPath(adj1, 4);
    for (auto ele : sp5)
    {
        if (ele == INT_MAX)
            cout << "INF ";
        else
            cout << ele << " ";
    }
    cout << "\n";

    return 0;
}
