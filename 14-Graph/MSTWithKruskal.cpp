// GFG Practice - Minimum Spanning Tree (Kruskal Algorithm)
// LeetCode 1584 - Min Cost to Connect All Points

#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int getParent(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = getParent(parent[u]);
    }
    
    bool unite(int u, int v){
        u = getParent(u);
        v = getParent(v);
        
        if(u == v)  return false;
        
        if(rank[u] < rank[v]){
            parent[u] = v;
            rank[v] += rank[u];
        }else{
            parent[v] = u;
            rank[u] += rank[v];
        }
        return true;
    }
};

class Solution {
  public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        DSU dsu(V);
        sort(edges.begin(), edges.end(), cmp);
        int res = 0;
        
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            
            if(dsu.unite(u, v)){
                res+= w;
            }
        }
        return res;
    }
};

int main(){
    
    Solution obj;

    // Test Case 1
    int V1 = 4;
    vector<vector<int>> edges1 = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };
    cout << obj.spanningTree(V1, edges1) << endl;

    // Test Case 2
    int V2 = 3;
    vector<vector<int>> edges2 = {
        {0,1,5},
        {1,2,3},
        {0,2,1}
    };
    cout << obj.spanningTree(V2, edges2) << endl;

    // Test Case 3
    int V3 = 5;
    vector<vector<int>> edges3 = {
        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7}
    };
    cout << obj.spanningTree(V3, edges3) << endl;

}

