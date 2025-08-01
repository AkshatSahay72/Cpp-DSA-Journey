#include <bits/stdc++.h>
using namespace std;

vector<string> pathContainer;
vector<int> dist;

void Dij(vector<pair<int, int>> adj[], int V, int src)
{
    // int V = adj.size();
    dist[src] = 0;
    // {cost, {vertex, path}}
    priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, greater<pair<int, pair<int, string>>>> pq;
    pq.push({0, {src, to_string(src)}});
    pathContainer[src] = to_string(src);
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second.first;
        string path = pq.top().second.second;
        pq.pop();

        for (auto it : adj[node])
        {
            // node = {it.first: Vertex, it.second: Cost}
            if (dist[it.first] == INT_MAX or
                dist[it.first] > dist[node] + it.second)
            {
                dist[it.first] = dist[node] + it.second;
                pathContainer[it.first] = pathContainer[node] + " -> " + to_string(it.first);
                pq.push({dist[it.first], {it.first, pathContainer[it.first]}});
            }
        }
    }
}

template <typename T>
void print(vector<T> arr)
{
    for (auto it : arr)
    {
        cout << it << "\n";
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    pathContainer.resize(n);
    dist.resize(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        // its a directed graph u -> v (with given cost);
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
    int src;
    cin >> src;
    Dij(adj, n, src);
    print(pathContainer);
    print(dist);
    return 0;
}