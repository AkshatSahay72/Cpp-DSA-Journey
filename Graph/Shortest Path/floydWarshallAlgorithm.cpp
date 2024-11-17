#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> warshall(unordered_map<int, list<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<vector<int>> adjMat(n, vector<int>(n, INT_MAX));

    // Initialize adjacency matrix
    for (auto node : adj) {
        int u = node.first;
        for (auto neighbour : node.second) {
            int v = neighbour.first;
            int dist = neighbour.second;
            adjMat[u][v] = dist;
        }
    }

    // Set diagonal to 0 (distance to itself)
    for (int i = 0; i < n; i++) {
        adjMat[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX) {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
    }

    return adjMat;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // Original Test Case 1
    unordered_map<int, list<pair<int, int>>> adj1 = {
        {0, {{1, 7}, {2, 1}, {3, 2}}},
        {1, {{0, 7}, {2, 3}, {3, 5}, {4, 1}}},
        {2, {{1, 3}, {0, 1}}},
        {3, {{0, 2}, {1, 5}, {4, 7}}},
        {4, {{1, 1}, {3, 7}}}
    };

    vector<vector<int>> shortestPath1 = warshall(adj1);

    cout << "Shortest Path Matrix for adj1:" << endl;
    printMatrix(shortestPath1);

    // Additional Test Case 1
    unordered_map<int, list<pair<int, int>>> adj2 = {
        {0, {{1, 5}, {2, 10}}},
        {1, {{0, 5}, {2, 2}}},
        {2, {{0, 10}, {1, 2}}}
    };

    vector<vector<int>> shortestPath2 = warshall(adj2);

    cout << "\nShortest Path Matrix for adj2:" << endl;
    printMatrix(shortestPath2);

    // Additional Test Case 2
    unordered_map<int, list<pair<int, int>>> adj3 = {
        {0, {{1, 1}}},
        {1, {{0, 1}}}
    };

    vector<vector<int>> shortestPath3 = warshall(adj3);

    cout << "\nShortest Path Matrix for adj3:" << endl;
    printMatrix(shortestPath3);

    // New Test Case with Unreachable Nodes (INF)
    unordered_map<int, list<pair<int, int>>> adj4 = {
        {0, {{1, 5}, {2, 3}}},
        {1, {{0, 5}}},
        {2, {{0, 3}}},
        {3, {{4, 2}}},
        {4, {{3, 2}}}
    };

    vector<vector<int>> shortestPath4 = warshall(adj4);

    cout << "\nShortest Path Matrix for adj4 (with INF):" << endl;
    printMatrix(shortestPath4);

    return 0;
}
