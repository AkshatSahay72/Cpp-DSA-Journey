#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string a = "";
    for (int i = 0; i < n; i++) {
        a += arr[i];
    }

    int ans = 0;
    vector<int> an;

    // Store indices of 'h' in vector an
    for (int i = 0; i < a.length()-1; i++) {
        if (a[i] == 'h') {
            an.push_back(i);
        }
    }

    // Count occurrences of 's' after 'h'
    for (int i = 0; i < an.size(); i++) {
        for (int j = an[i] + 1; j < a.length(); j++) {
            if (a[j] == 's') {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
