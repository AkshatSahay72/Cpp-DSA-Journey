// GFG Practice: Merge two Binary Max Heaps

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    void heapify(vector<int> &a, int n, int i){
        int largest = i;
        int left = i*2 + 1;
        int right = i*2 + 2;
        
        if(left<n && a[largest]<a[left])   largest = left;
        if(right<n && a[largest]<a[right])   largest = right;
        
        if(i != largest){
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }
  
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        for(auto i: b){
            a.push_back(i);
        }
        
        n = n+m;
        
        for(int i = n/2; i>=0; i--)
            heapify(a, n, i);
        return a;
    }
};

int main() {
    Solution s;

    vector<int> a1 = {10, 5, 6, 2};
    vector<int> b1 = {12, 7, 9};
    auto r1 = s.mergeHeaps(a1, b1, a1.size(), b1.size());
    for(int x : r1) cout << x << " ";
    cout << endl;

    vector<int> a2 = {20, 18, 15};
    vector<int> b2 = {30, 25};
    auto r2 = s.mergeHeaps(a2, b2, a2.size(), b2.size());
    for(int x : r2) cout << x << " ";
    cout << endl;

    vector<int> a3 = {1};
    vector<int> b3 = {2, 3, 4};
    auto r3 = s.mergeHeaps(a3, b3, a3.size(), b3.size());
    for(int x : r3) cout << x << " ";
    cout << endl;

    return 0;
}
