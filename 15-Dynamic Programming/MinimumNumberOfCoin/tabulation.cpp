#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minimumElements(vector<int>&nums, int x, vector<int> dp){
    int n = nums.size();
    for (int i = 1; i <= x;i++){
        for (int j = 0; j < n;j++){
            if (i - nums[j] >= 0 && dp[i-nums[j]]!=INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
        }
    }

    return dp[x];
}

int main(){
    int amount = 10;
    vector<int> nums = {1, 2, 5};
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    cout << minimumElements(nums, amount, dp);
}