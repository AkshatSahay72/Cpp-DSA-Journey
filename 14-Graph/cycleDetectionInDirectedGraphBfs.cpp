#include<bits/stdc++.h>
using namespace std;

bool detectCycleInDirectedGraph(vector<pair<int, int>> edges){
    unordered_map<int, list<int>> adj;
    for(auto edge: edges){
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);

        if(adj.find(v) == adj.end())
            adj[v] = {};
    }

    unordered_map<int, int> indegree;
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(auto node: adj){
        if(indegree[node.first] == 0){
            q.push(node.first);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return (cnt != adj.size());
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

