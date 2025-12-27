#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<char>> &matrix, int i, int j, int &maxi){
    if(i>=matrix.size() || j>=matrix[0].size())
        return 0;

    int right = solve(matrix, i, j+1, maxi);
    int dia = solve(matrix, i+1, j+1, maxi);
    int down = solve(matrix, i+1, j, maxi);

    if(matrix[i][j] == '1'){
        int ans = 1 + min(right, min(dia, down));
        maxi = max(maxi, ans);
        return ans;
    }
    return 0;
}

int minimalSquare(vector<vector<char>> &matrix){
    int maxi = 0;   
    for(int i = 0;i<matrix.size();i++){
        for(int j = 0; j<matrix[0].size();j++){
            solve(matrix, i, j, maxi);
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