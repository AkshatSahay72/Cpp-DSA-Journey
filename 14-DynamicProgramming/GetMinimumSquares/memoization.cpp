#include<iostream>
#include<vector>
using namespace std;

int getMin(int n, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = n;
    for(int i = 1; i*i<=n ; i++){
        ans = min(ans, 1 + getMin(n - (i*i), dp));
    }
    dp[n] = ans;
    return dp[n];
}

int main(){
    int n = 100;
    vector<int> dp(n+1, -1);
    cout<<getMin(n, dp)<<endl;
}