#include<iostream>
#include<vector>
using namespace std;

int fiboSpaceOptimised(int n){

    int prev1 = 1;
    int prev2 = 0;

    for (int i = 2; i <= n;i++){
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main(){
    int n = 6;
    vector<int> dp(n + 1, -1);

    cout << fiboSpaceOptimised(n) << endl;

}