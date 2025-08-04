#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2;i<n;i++){
            int cur = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = cur;
        }
        return min(prev1 ,prev2);


    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = solve(cost,n);
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> cost = {740, 696, 421, 504, 795, 894, 724, 562, 234};
    cout << sol.minCostClimbingStairs(cost) << endl;
}