// Leet 1039

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int magic(vector<int> &v, int i, int j, vector<vector<int>> &dp){
    if(i+1 == j)    return 0;

    if(dp[i][j] != INT_MAX) return dp[i][j];

    for(int k = i+1; k<j;k++){
        dp[i][j] = min(dp[i][j], v[i]*v[j]*v[k] + magic(v, i, k, dp) + magic(v, k, j, dp));
    }
    return dp[i][j];
}

int minScoreTriagulation(vector<int> &values){
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
    return magic(values, 0, values.size() - 1, dp);
}

int main() {
    vector<int> values = {1, 3, 1, 4, 1, 5};  // sample input
    cout << minScoreTriagulation(values) << endl;
    return 0;
}