/*
GFG Practice: Minimum Spanning Tree (Prim's Algorithm)
LeetCode 1584: Min Cost to Connect All Points
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> primsPQ(int n, vector<pair<pair<int,int>,int>> &g){

    unordered_map<int,list<pair<int,int>>> adj;

    for(auto &i : g){
        int u = i.first.first;
        int v = i.first.second;
        int wt = i.second;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<bool> vis(n,false);
    vector<int> parent(n,-1);
    vector<int> key(n,INT_MAX);

    pq.push({0,0});
    key[0] = 0;

    while(!pq.empty()){

        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]) continue;

        vis[node] = true;

        for(auto &i : adj[node]){

            int v = i.first;
            int weight = i.second;

            if(!vis[v] && weight < key[v]){
                key[v] = weight;
                parent[v] = node;

                pq.push({weight,v});
            }
        }
    }

    vector<pair<pair<int,int>,int>> res;

    for(int i=1;i<n;i++){
        res.push_back({{parent[i],i},key[i]});
    }

    return res;
}



int main(){

    int n = 5;

    vector<pair<pair<int,int>,int>> g = {
        {{0,1},2},
        {{0,3},6},
        {{1,2},3},
        {{1,3},8},
        {{1,4},5},
        {{2,4},7},
        {{3,4},9}
    };

    auto ans = primsPQ(n,g);

    for(auto &i : ans){
        cout<<i.first.first<<" - "<<i.first.second<<" : "<<i.second<<endl;
    }

    cout<<endl;

    // Test 2
    n = 3;
    g = {
        {{0,1},1},
        {{1,2},2},
        {{0,2},3}
    };

    ans = primsPQ(n,g);

    for(auto &i : ans){
        cout<<i.first.first<<" - "<<i.first.second<<" : "<<i.second<<endl;
    }

    cout<<endl;

    // Test 3
    n = 4;
    g = {
        {{0,1},10},
        {{0,2},6},
        {{0,3},5},
        {{1,3},15},
        {{2,3},4}
    };

    ans = primsPQ(n,g);

    for(auto &i : ans){
        cout<<i.first.first<<" - "<<i.first.second<<" : "<<i.second<<endl;
    }

}