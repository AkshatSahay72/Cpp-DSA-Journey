#include<bits/stdc++.h>
using namespace std;

vector<int> dijkshtra(unordered_map<int, list<pair<int, int>>> adj, int src){

    vector<int> dist(adj.size(), INT_MAX);
    set<pair<int, int>> st;

    dist[src] = 0;
    st.insert(make_pair(0, src));

    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour: adj[topNode]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDist + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}


int main()
{
    // Test graph adjacency list
    unordered_map<int, list<pair<int, int>>> adj1 = {
        {0, {{1, 7}, {2, 1}, {3, 2}}},
        {1, {{0, 7}, {2, 3}, {3, 5}, {4, 1}}},
        {2, {{1, 3}, {0, 1}}},
        {3, {{0, 2}, {1, 5}, {4, 7}}},
        {4, {{1, 1}, {3,7}}}
        };

    // Test Case 1
    cout << "Test Case 1: Source Node = 0\n";
    vector<int> sp1 = dijkshtra(adj1, 0);
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
    vector<int> sp2 = dijkshtra(adj1, 1);
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
    vector<int> sp3 = dijkshtra(adj1, 2);
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
    vector<int> sp4 = dijkshtra(adj1, 3);
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
    vector<int> sp5 = dijkshtra(adj1, 4);
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
