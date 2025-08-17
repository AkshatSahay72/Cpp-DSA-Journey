#include<iostream>
#include<vector>
using namespace std;

int magic(vector<int> &nums){
    int n = nums.size();

    if(n == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }
    return prev1;
}

int houseRobbery(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];

    vector<int> first, second;
    for (int i = 0; i < n;i++){
        if(i != n-1)
            first.push_back(nums[i]);
        if(i != 0)
            second.push_back(nums[i]);
    }
    return max(magic(first), magic(second));
}

int main(){
    vector<int> nums = {2, 3, 2};
    cout << houseRobbery(nums) << endl;
}