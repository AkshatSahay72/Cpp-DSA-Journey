#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(const vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList) {
    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // Add the edge in both directions (undirected graph)
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

vector<int> BFS(int vertex, const vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;

    // Prepare the adjacency list
    prepareAdjList(edges, adjList);

    // Perform BFS on each component
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode);

                for (auto neighbor : adjList[frontNode]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    // Test Case 1: Simple Graph with 5 Nodes
    int vertex1 = 5;
    vector<pair<int, int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    cout << "Test Case 1: ";
    for (int node : BFS(vertex1, edges1)) cout << node << " ";
    cout << endl;

    // Test Case 2: Graph with Multiple Components
    int vertex2 = 6;
    vector<pair<int, int>> edges2 = {{0, 1}, {2, 3}, {4, 5}};
    cout << "Test Case 2: ";
    for (int node : BFS(vertex2, edges2)) cout << node << " ";
    cout << endl;

    // Test Case 3: Complete Graph
    int vertex3 = 4;
    vector<pair<int, int>> edges3 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    cout << "Test Case 3: ";
    for (int node : BFS(vertex3, edges3)) cout << node << " ";
    cout << endl;

    // Test Case 4: Single Node
    int vertex4 = 1;
    vector<pair<int, int>> edges4 = {};
    cout << "Test Case 4: ";
    for (int node : BFS(vertex4, edges4)) cout << node << " ";
    cout << endl;

    // Test Case 5: Disconnected Graph with Isolated Nodes
    int vertex5 = 7;
    vector<pair<int, int>> edges5 = {{0, 1}, {0, 2}, {3, 4}};
    cout << "Test Case 5: ";
    for (int node : BFS(vertex5, edges5)) cout << node << " ";
    cout << endl;

    return 0;
}