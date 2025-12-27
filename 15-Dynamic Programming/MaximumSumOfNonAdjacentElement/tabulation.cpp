#include<iostream>
#include<vector>
using namespace std;



int maxSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i<n; i++){
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

int main(){
    vector<int> nums = {5, 5, 10, 100, 10, 5};
    cout << maxSum(nums) << endl;
}