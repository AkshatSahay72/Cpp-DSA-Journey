#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int res = -1;
        if (i - x >= 0 && dp[i - x] != -1)
            res = max(res, dp[i - x] + 1);
        if (i - y >= 0 && dp[i - y] != -1)
            res = max(res, dp[i - y] + 1);
        if (i - z >= 0 && dp[i - z] != -1)
            res = max(res, dp[i - z] + 1);

        dp[i] = res;
    }

    return (dp[n] < 0) ? 0 : dp[n];
}

int main()
{
    cout << cutSegments(4, 2, 1, 1) << endl;
}