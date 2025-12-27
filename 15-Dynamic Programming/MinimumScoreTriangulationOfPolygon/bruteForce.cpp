// Leet 1039

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int magic(vector<int> &v, int i, int j){
    if(i+1 == j)    return 0;

    int ans = INT_MAX;
    for(int k = i+1; k<j;k++){
        ans = min(ans, v[i]*v[j]*v[k] + magic(v, i, k) + magic(v, k, j));
    }
    return ans;
}

int minScoreTriagulation(vector<int> &values){
    return magic(values, 0, values.size() - 1);
}

int main() {
    vector<int> values = {1, 3, 1, 4, 1, 5};  // sample input
    cout << minScoreTriagulation(values) << endl;
    return 0;
}