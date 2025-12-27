#include <iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

long long int countDearangements(int n,vector<int> dp)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;
    if(dp[n] !=-1) return dp[n];

    dp[n] = (((n-1)%MOD)*(countDearangements(n-1, dp)% MOD + countDearangements(n-2,dp)% MOD))% MOD ;

    return dp[n];

}

int main()
{   
    int n = 5;
    vector<int> dp(n+1, -1);
    cout<<countDearangements(n,dp)<<endl;
}