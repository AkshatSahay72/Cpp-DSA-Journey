#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    vector<int> temp;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<int> &colCheck, vector<int> &leftDig, vector<int> &rightDig, int n){
    // Row
    if(colCheck[row] == 1)
        return false;

    // Left Diagonal
    if(leftDig[row + col] == 1)
        return false;

    // Right Diagonal
    if(rightDig[n - 1 + col - row] == 1)
        return false;

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board,vector<int> &colCheck,
    vector<int> &leftDig, vector<int> &rightDig, int n){
    if(col == n){
        addSolution(ans, board,n);
        return;
    }

    for(int row = 0; row<n;row++){
        if(isSafe(row, col, colCheck, leftDig, rightDig, n)){
            board[row][col] = 1;
            colCheck[row] = 1;
            leftDig[row + col] = 1;
            rightDig[n - 1 + col - row] = 1;

            solve(col + 1, ans, board,colCheck, leftDig, rightDig, n);

            leftDig[row + col] = 0;
            rightDig[n - 1 + col - row] = 0;
            colCheck[row] = 0;
            board[row][col] = 0;

        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    vector<int> colCheck(n,0);
    vector<int> leftDig(2*n,0);
    vector<int> rightDig(2*n,0);

    solve(0, ans, board,colCheck, leftDig, rightDig, n);
    return ans;
}

int main(){
    int n = 5;
    vector<vector<int>> solutions = nQueens(n);

    if (solutions.size() == 0) {
        cout << "No solutions exist for N = " << n << endl;
        return 0;
    }

    int boardCount = 1;
    for (auto sol : solutions) {
        cout << "Solution " << boardCount++ << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sol[i * n + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
