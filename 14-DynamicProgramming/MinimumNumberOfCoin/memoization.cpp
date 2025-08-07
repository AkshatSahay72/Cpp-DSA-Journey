#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minimumElements(vector<int>& nums, int x, vector<int> dp){
    int n = nums.size();
    if(x == 0)
        return 0;
    if(x<0)
        return INT_MAX;
    if(dp[x]!=-1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < n;i++){
        int ans = minimumElements(nums, x - nums[i], dp);
        if(ans!=INT_MAX)
            mini = min(mini, 1 + ans);

    }
    dp[x] = mini;

    return mini;
}


int main(){
    int amount = 11;
    vector<int> nums = {1, 2, 5};
    vector<int> dp(amount + 1, -1);
    cout << minimumElements(nums, amount, dp);
}