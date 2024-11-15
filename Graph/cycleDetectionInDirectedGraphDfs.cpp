#include <bits/stdc++.h>
using namespace std;

void createAdjList(vector<pair<int, int>> edge, unordered_map<int, list<int>> &adj)
{
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].first;
        int v = edge[i].second;

        adj[u].push_back(v);
    }
}

bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleFound = checkCycleDfs(neighbour, visited, dfsVisited, adj);
            if (cycleFound)
            {
                return true;
            }
        }
        else if (dfsVisited[node])
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

    for (int i = 1; i <= adj.size(); i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDfs(i, visited, dfsVisited, adj);
            if (cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<pair<int, int>> edge = {{1, 2}, {2, 4}, {3, 7}, {3, 8}, {4, 5}, {5, 6}, {6, 4}};
    cout << detectCycleInDirectedGraph(edge);
}