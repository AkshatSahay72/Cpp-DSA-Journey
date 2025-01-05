#include <bits/stdc++.h>
using namespace std;

void heapLogic(vector<int> &arr, int n, int i)
{
    int large = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[large])
    {
        large = left;
    }
    if (right < n && arr[right] > arr[large])
    {
        large = right;
    }

    if (i != large)
    {
        swap(arr[large], arr[i]);
        heapLogic(arr, n, large);
    }
}

void print(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapLogic(arr, n, i);
    }

    /*for(int i = n - 1; i > 0; i--){
    swap(arr[0], arr[i]);
    heapLogic(arr, i, 0);
    }*/
    print(arr);
    return 0;
}