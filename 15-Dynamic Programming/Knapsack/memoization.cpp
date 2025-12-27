#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){ 
    // Base Case
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }else{
            return 0;
        }
    }

    if(dp[index][capacity] !=-1) return dp[index][capacity];
    int include = 0;
    int exclude = 0;
    if(weight[index]<=capacity){
        include = value[index] + solve(weight, value, index-1,capacity-weight[index],dp);

    }
    exclude = solve(weight, value, index-1,capacity,dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return solve(weight, value, n-1, maxWeight, dp);
}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int n = 4;
    int maxCapacity = 5;
    cout<<knapsack(weight, value, n, maxCapacity)<<endl;

}