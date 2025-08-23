#include <iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

long long int countDearangements(int n)
{
    int prev2 = 0;
    int prev1 = 1;


    for(int i = 3; i<=n;i++){
        int ans = ((i-1)%MOD * (prev1%MOD +prev2%MOD))%MOD;
        prev2 = prev1; 
        prev1 = ans;
    }
    return prev1;  

}

int main()
{   
    int n = 5;
    
    cout<<countDearangements(n)<<endl;
}