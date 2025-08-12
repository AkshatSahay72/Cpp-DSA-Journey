#include<iostream>
#include<vector>
using namespace std;



int maxSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }
    return prev1;
}

int main(){
    vector<int> nums = {5, 5, 10, 100, 10, 5};
    cout << maxSum(nums) << endl;
}