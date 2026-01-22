// GFG Practice: Kth smallest element
// LeetCode: Kth Smallest Element in an Array (215)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};

int main() {
    Solution s;

    vector<int> t1 = {7, 10, 4, 3, 20, 15};
    cout << s.kthSmallest(t1, 3) << endl; // expected 7

    vector<int> t2 = {2, 1, 3, 5, 4};
    cout << s.kthSmallest(t2, 1) << endl; // expected 1

    vector<int> t3 = {12, 3, 5, 7, 19};
    cout << s.kthSmallest(t3, 4) << endl; // expected 12

    return 0;
}
