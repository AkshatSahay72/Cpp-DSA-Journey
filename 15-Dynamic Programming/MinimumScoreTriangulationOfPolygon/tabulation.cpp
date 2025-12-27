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
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i = n-1;i>=0;i--){
        for(int j = i+2;j<n;j++){   
            dp[i][j] = INT_MAX;
            for(int k = i+1;k<j;k++){
                dp[i][j] = min(dp[i][j], values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][n-1];

}

int main() {
    vector<int> values = {1, 3, 1, 4, 1, 5};  // sample input
    cout << minScoreTriagulation(values) << endl;
    return 0;
}