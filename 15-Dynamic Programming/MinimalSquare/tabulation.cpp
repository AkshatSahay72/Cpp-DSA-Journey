#include<iostream>
#include<vector>
using namespace std;

int minimalSquare(vector<vector<char>> &matrix){
    int maxi = 0;   
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));

    for(int i = n-1; i>=0; i--){
        for(int j = m-1;j>=0;j--){
            if(matrix[i][j] == '1'){
                int right = (j+1 < m) ? dp[i][j+1] : 0;
                int down  = (i+1 < n) ? dp[i+1][j] : 0;
                int dia   = (i+1 < n && j+1 < m) ? dp[i+1][j+1] : 0;
                dp[i][j] = 1 + min(right, min(dia, down));
                maxi = max(maxi, dp[i][j]);
            }
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