#include<iostream>
#include<vector>
using namespace std;

int magic(vector<int> &days, vector<int> &costs, int n, int index, vector<int> &dp){
    if(index >= n){
        return 0;
    }
    if(dp[index] != -1) return dp[index];

    int day1 = costs[0] + magic(days, costs, n, index+1, dp);

    int i;
    for(i = index; i<n && days[i] < days[index]+7 ;i++);
    int day7 = costs[1] + magic(days, costs, n, i, dp);

    for(i = index; i< n && days[i]< days[index]+30;i++);
    int day30 = costs[2] + magic(days, costs, n, i, dp);

    dp[index] = min(day1, min(day7, day30));
    return dp[index];

}

int minCost(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n+1, -1);
    return magic(days, costs, n, 0, dp);
}

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout<<minCost(days, costs)<<endl; // 11
}