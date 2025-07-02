#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

class Solution{
    public:
    vector<int> nextSmallest(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);

        vector<int> ans(n, 0);
        for (int i = n - 1; i >=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallest(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);

        vector<int> ans(n, 0);

        for (int i = 0; i < n;i++){
            while(s.top()!=-1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int maxHist(vector<int> height, int n){
        vector<int> next = nextSmallest(height, n);
        vector<int> prev = prevSmallest(height, n);
        int area = INT_MIN;

        for (int i = 0; i < n;i++){
            int h = height[i];
            if(next[i] == -1)
                next[i] = n;

            int w = next[i] - prev[i] - 1;
            area = max(area, h * w);
        }
        return area;
    }

    int maxArea(vector<vector<int>> mat){
        int n = mat.size();
        int m = mat[0].size();

        int area = maxHist(mat[0], m);

        for (int i = 1; i < n;i++){
            for (int j = 0; j < m;j++){
                if(mat[i][j])
                    mat[i][j] += mat[i - 1][j];
                else
                    mat[i][j] = 0;
            }
            area = max(area, maxHist(mat[i], m));
        }
        return area;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Simple 2x2 full of 1s
    vector<vector<int>> mat1 = {
        {1, 1},
        {1, 1}
    };

    // Test Case 2: Mixed values
    vector<vector<int>> mat2 = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 0}
    };

    // Test Case 3: Edge case, single row
    vector<vector<int>> mat3 = {
        {1, 0, 1, 1, 1}
    };

    cout << "Test Case 1 Result: " << sol.maxArea(mat1) << endl;  // Expected: 4
    cout << "Test Case 2 Result: " << sol.maxArea(mat2) << endl;  // Expected: 6
    cout << "Test Case 3 Result: " << sol.maxArea(mat3) << endl;  // Expected: 3

    return 0;
}