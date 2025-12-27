#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    // vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);

    for(int w = 0; w<=maxWeight;w++){
        if(weight[w]<=maxWeight){
            prev[w] = value[0];
        }
    }
    for(int index=1;index<n;index++){
        for(int w = 0; w<=maxWeight;w++){
            int include = 0;
            if(weight[index]<=w)
                include = value[index] + prev[w - weight[index]];  
        
            int exclude = prev[w];  
            curr[w] = max(include, exclude);
        }

        prev = curr;
    }
    return prev[maxWeight];

}

int main(){
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int n = 4;
    int maxCapacity = 5;
    cout<<knapsack(weight, value, n, maxCapacity)<<endl;

}