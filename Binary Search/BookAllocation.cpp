#include <iostream>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid)
{
    int count = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            count++;
            if (count > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocation(int arr[], int n, int m)
{
    int s = 0;
    int e = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        e += arr[i];
    }

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (ispossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return mid;
}

int main()
{
    int n = 6;
    int arr[n] = {10, 20, 30, 40};
    int m = 3;
    cout << allocation(arr, n, m);
}