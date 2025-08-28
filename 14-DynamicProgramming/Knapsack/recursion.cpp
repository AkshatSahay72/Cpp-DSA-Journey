#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity){ 
    // Base Case
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }else{
            return 0;
        }
    }
    int include = 0;
    int exclude = 0;
    if(weight[index]<=capacity){
        include = value[index] + solve(weight, value, index-1,capacity-weight[index]);

    }
    exclude = solve(weight, value, index-1,capacity);

    return max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    return solve(weight, value, n-1, maxWeight);
}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int n = 4;
    int maxCapacity = 5;
    cout<<knapsack(weight, value, n, maxCapacity)<<endl;

}