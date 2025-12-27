#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// int magic(vector<int>& nums)

int minimumElements(vector<int>& nums, int x){
    int n = nums.size();
    if(x == 0)
        return 0;
    if(x<0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < n;i++){
        int ans = minimumElements(nums, x - nums[i]);
        if(ans!=INT_MAX)
            mini = min(mini, 1 + ans);

    }
    return mini;
}

int main(){
    vector<int> nums = {1, 2, 3};
    cout << minimumElements(nums, 7);
}