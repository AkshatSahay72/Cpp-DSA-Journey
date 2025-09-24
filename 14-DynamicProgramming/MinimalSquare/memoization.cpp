#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i>=matrix.size() || j>=matrix[0].size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = solve(matrix, i, j+1, maxi, dp);
    int dia = solve(matrix, i+1, j+1, maxi, dp);
    int down = solve(matrix, i+1, j, maxi, dp);

    if(matrix[i][j] == '1'){
        int ans = 1 + min(right, min(dia, down));
        maxi = max(maxi, ans);
        dp[i][j] = ans;
        return dp[i][j];
    }
    return 0;
}

int minimalSquare(vector<vector<char>> &matrix){
    int maxi = 0;   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int i = 0;i<n;i++){
        for(int j = 0; j<m;j++){
            solve(matrix, i, j, maxi,dp);
        }
    }
    return maxi * maxi;
}

int main(){
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout<<minimalSquare(matrix)<<endl;
}