#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minCost(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;

    for(int index = n-1; index>=0; index++){
        int day1 = costs[0] + dp[index+1];

        int i;
        for(i = index; i<n && days[i] < days[index] + 7;i++);
        int day7 = costs[1] + dp[i];

        i = index; // reset
        for(; i<n && days[i] < days[index] + 30;i++);
        int day30 = costs[2] + dp[i];

        dp[index] = min(day1, min(day7, day30));

    }
    return dp[0];
}

int main()
{
    cout << "Program started\n";
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout << "Answer: " << minCost(days, costs) << endl;

}