#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &cost, int n,vector<int> &dp){
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];

        if(dp[n]!=-1)
            return dp[n];

        int ans = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        dp[n] = ans;
        return  ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int ans = min(solve(cost,n-1, dp),solve(cost, n-2,dp));
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> cost = {740, 696, 421, 504, 795, 894, 724, 562, 234};
    cout << sol.minCostClimbingStairs(cost) << endl;
}
