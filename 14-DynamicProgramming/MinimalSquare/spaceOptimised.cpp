#include<iostream>
#include<vector>
using namespace std;

int minimalSquare(vector<vector<char>> &matrix){
    int maxi = 0;   
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int i = n-1; i>=0; i--){
        for(int j = m-1;j>=0;j--){
            if(matrix[i][j] == '1'){
                int right = curr[j+1];
                int down  =next[j];
                int dia   = next[j+1];
                curr[j] = 1 + min(right, min(dia, down));
                maxi = max(maxi, curr[j]);
            }else 
            curr[j] = 0;
        }
        next = curr;
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