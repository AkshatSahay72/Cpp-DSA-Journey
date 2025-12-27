#include<iostream>
#include<vector>
using namespace std;

int minCost(vector<int> &days, vector<int> costs, int index){
    if(days.size() <= index){
        return 0;
    }

    // For 1 Day
    int day1 = costs[0] + minCost(days, costs, index+1);

    // For 7 Days
    int i;
    for(i = index; i<days.size() && days[i] < days[index] + 7;i++);
    int day7 = costs[1] + minCost(days, costs, i);

    // For 30 Days
    for(i = index; i<days.size() && days[i] < days[index]+30;i++);
    int day30 = costs[2] + minCost(days, costs, i);

    return min(day1, min(day7, day30));
}

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    cout << minCost(days, costs, 0) << endl; // 11

}
