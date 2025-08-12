#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &nums, int n, vector<int> &dp){
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];

    if(dp[n]!=-1)
        return dp[n];

    int incl = solve(nums, n - 2, dp) + nums[n];
    int excl = solve(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int maxSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solve(nums, n, dp);
    return ans;
}

int main(){
    vector<int> nums = {5, 5, 10, 100, 10, 5};
    cout << maxSum(nums) << endl;
}