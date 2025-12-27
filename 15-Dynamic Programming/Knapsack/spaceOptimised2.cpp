#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    // vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);

    for(int w = maxWeight; w>=0;w--){
        if(weight[w]<=maxWeight){
            curr[w] = value[0];
        }
    }
    for(int index=1;index<n;index++){
        for(int w = maxWeight; w>=0;w--){
            int include = 0;
            if(weight[index]<=w)
                include = value[index] + curr[w - weight[index]];  
        
            int exclude = curr[w];  
            curr[w] = max(include, exclude);
        }
    }
    return curr[maxWeight];

}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int n = 4;
    int maxCapacity = 5;
    cout<<knapsack(weight, value, n, maxCapacity)<<endl;

}