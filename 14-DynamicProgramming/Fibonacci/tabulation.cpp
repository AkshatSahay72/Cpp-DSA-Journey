#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}


int main(){
    int n = 6;
    vector<int> dp(n + 1, -1);

    cout << fibo(n, dp) << endl;

}