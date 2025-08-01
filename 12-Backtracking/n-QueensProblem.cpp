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

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col-1;

    while (y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
    }
    y = col-1;
    x = row -1;
    while(x>=0 && y >=0){
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    y = col-1;
    x = row+1;
    while(x<n && y >= 0){
        if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    if(col == n){
        addSolution(ans, board,n);
        return;
    }

    for(int row = 0; row<n;row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;

        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main(){
    int n = 9;
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
