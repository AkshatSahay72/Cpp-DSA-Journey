/*
GFG Practice: Minimum Spanning Tree (Prim's Algorithm)
LeetCode 1584: Min Cost to Connect All Points
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){

    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt}); // FIX
        adj[v].push_back({u, wt});
    }

    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);  

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i<n;i++){
        int u = -1;
        int mini = INT_MAX;

        for(int v = 0; v < n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for(auto it: adj[u]){
            int vt = it.first;
            int wt = it.second;

            if(mst[vt] == false && wt < key[vt]){
                parent[vt] = u;
                key[vt] = wt;
            }
        }
    }

    vector<pair<pair<int, int>, int>> res;

    for(int i = 1; i < n; i++){
        res.push_back({{parent[i], i}, key[i]});
    }

    return res;
}

int main(){

    int n = 5;
    int m = 7;

    vector<pair<pair<int,int>,int>> g = {
        {{0,1},2},
        {{0,3},6},
        {{1,2},3},
        {{1,3},8},
        {{1,4},5},
        {{2,4},7},
        {{3,4},9}
    };

    auto ans = calculatePrimsMST(n,m,g);

    for(auto &i : ans){
        cout << i.first.first << " - " << i.first.second << " : " << i.second << endl;
    }

    cout << endl;

    // Test case 2
    n = 4;
    g = {
        {{0,1},10},
        {{0,2},6},
        {{0,3},5},
        {{1,3},15},
        {{2,3},4}
    };

    ans = calculatePrimsMST(n,g.size(),g);

    for(auto &i : ans){
        cout << i.first.first << " - " << i.first.second << " : " << i.second << endl;
    }

    cout << endl;

    // Test case 3
    n = 3;
    g = {
        {{0,1},1},
        {{1,2},2},
        {{0,2},3}
    };

    ans = calculatePrimsMST(n,g.size(),g);

    for(auto &i : ans){
        cout << i.first.first << " - " << i.first.second << " : " << i.second << endl;
    }

}