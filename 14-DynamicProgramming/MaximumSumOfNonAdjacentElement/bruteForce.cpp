#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &nums, int n){
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];

    int incl = solve(nums, n - 2) + nums[n];
    int excl = solve(nums, n - 1) + 0;

    return max(incl, excl);
}

int maxSum(vector<int> &nums){
    int n = nums.size();
    int ans = solve(nums, n - 1);
    return ans;
}

int main(){
    vector<int> nums = {5, 5, 10, 100, 10, 5};
    cout << maxSum(nums) << endl;
}