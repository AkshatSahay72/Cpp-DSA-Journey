#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> nextSmallest(vector<int>& heights, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallest(vector<int> heights, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int curr = heights[i];
            while(s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);

        next = nextSmallest(heights, n);
        prev = prevSmallest(heights, n);

        int area = INT_MIN;
        for(int i = 0; i < n; i++){
            int h = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int w = next[i] - prev[i] - 1;
            area = max(area, h * w);
        }
        return area;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << maxArea << endl;
    return 0;
}
