#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    bool isSafe(int newx, int newy, int n, vector<vector<int>> maze, vector<vector<bool>> visited){
        return (newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == 0 && maze[newx][newy] == 1);
    }

    void magic(int x, int y, int n, vector<vector<int>> maze, vector<vector<bool>> &visited,
    string path, vector<string> &ans){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        // Down
        if(isSafe(x+1,y,n,maze,visited)){
            visited[x][y] = 1;
            magic(x + 1, y, n, maze, visited, path+'D', ans);
            visited[x][y] = 0;
        }
        
        //Left
        if(isSafe(x,y-1,n,maze,visited)){
            visited[x][y] = 1;
            magic(x, y - 1, n, maze, visited, path + 'L', ans);
            visited[x][y] = 0;
        }
        
        //Right
        if(isSafe(x,y+1,n,maze,visited)){
            visited[x][y] = 1;
            magic(x , y+1, n, maze, visited, path+'R', ans);
            visited[x][y] = 0;
        }
        
        //Up
        if(isSafe(x-1,y,n,maze,visited)){
            visited[x][y] = 1;
            magic(x - 1, y, n, maze, visited, path+'U', ans);
            visited[x][y] = 0;
        }
    }

    vector<string> ratInTheMaze(vector<vector<int>> maze){
        vector<string> ans;
        int n = maze.size();
        string path = "";
        vector<vector<bool>> visited(n, vector<bool>(n, 0));

        magic(0, 0, n, maze, visited, path,ans);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> maze = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
    // Output: ["DDRR", "RRDD"]

    vector<string> ans = sol.ratInTheMaze(maze);
    for(auto i: ans){
        cout << i << " , ";
    }
    cout << endl;
}