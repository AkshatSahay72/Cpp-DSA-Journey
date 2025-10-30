#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int> &obstacles, int curLane, int curPos){
    if(curPos == obstacles.size() - 1)  return 0;

    if(obstacles[curPos+1] != curLane){
        return solve(obstacles, curLane, curPos+1);
    }
    int ans = INT_MAX;
    for(int i = 1; i<=3; i++){
        if(curLane != i && obstacles[curPos] != i)
        ans = min(ans, 1 + solve(obstacles,i,curPos));
    }
    return ans;

}

int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles, 2, 0);
}

int main(){
    vector<int> obstacles = {0,1,2,3,0};
    cout<< minSideJumps(obstacles)<<endl;
}