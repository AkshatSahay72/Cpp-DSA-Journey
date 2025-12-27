#include <iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

long long int countDearangements(int n,vector<int> dp)
{
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i<=n;i++){
        dp[i] = ((i-1)%MOD * (dp[i-1]%MOD +dp[i-2]%MOD))%MOD;
    }
    return dp[n];  

}

int main()
{   
    int n = 5;
    vector<int> dp(n+1, -1);
    
    cout<<countDearangements(n,dp)<<endl;
}