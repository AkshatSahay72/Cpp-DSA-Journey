#include<iostream>
#include<vector>
using namespace std;
vector<string> magic(vector<vector<int> &m, int n){
}

int main(){
    int arr[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> ans;
    int srcx = 0;
    int srcy = 0;

    int visited[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    string path = "";
    magic(m, n, srcx, srcy, visited, path);
}