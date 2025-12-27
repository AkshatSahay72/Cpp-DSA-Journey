#include<iostream>
#include<vector>
using namespace std;

int solve(int n, int k, vector<int> dp){
    if(n==1) return k;
    if(n==2) return k + (k * (k-1));

    if(dp[n] != -1) return dp[n];
    
    dp[n] = (solve(n-2,k,dp) * (k-1)) + (solve(n-1, k, dp) * (k-1));
    return dp[n];

}

int numberOfWays(int n, int k){
    vector<int> dp(n+1, -1);
    return solve(n, k, dp);
}

int main(){
    cout<< numberOfWays(3,2)<<endl;
}
