#include <iostream>
using namespace std;

int search(int *arr, int size, int key)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[size - 1] == key)
    {
        int ans = size - 1;
        return ans;
    }
    else
    {
        return search(arr, size - 1, key);
    }
}

int main()
{
    int arr[5] = {4, 7, 8, 9, 11};
    int size = 5;

    int ans = search(arr, size, 17);
    cout << ans << endl;
}