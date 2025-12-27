#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        bool isSafe(int row, int col, vector<vector<int>> &mat, int val){
            for (int i = 0; i < 9;i++){
                if(mat[row][i] == val)
                    return false;
                
                if(mat[i][col] == val)
                    return false;
                
                if(mat[3*(row/3)+i/3][3*(col/3)+i%3] == val) // Important hai ye
                    return false;
            }
            return true;
        }

        bool magic(vector<vector<int>> &mat){
            int n = 9;
            for (int row = 0; row < n;row++){
                for (int col = 0; col < n; col++){
                    if(mat[row][col] == 0){
                        for (int i = 0; i <= 9;i++){
                            if(isSafe(row, col, mat, i)){
                                mat[row][col] = i;
                                bool isValid = magic(mat);
                                if(isValid)
                                    return true;
                                mat[row][col] = 0;
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        void sudokuSolver(vector<vector<int>> &mat){
            magic(mat);
        }
};

int main(){
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    Solution s;
    s.sudokuSolver(board);

    cout << "Solved Sudoku:\n";
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}