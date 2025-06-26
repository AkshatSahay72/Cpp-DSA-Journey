#include <iostream>
using namespace std;

int magic(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }
    int sum = arr[size - 1] + magic(arr + 1, size - 1);
    return sum;
}

int main()
{
    int arr[5] = {1, 1, 1, 1, 1};
    int size = 5;

    int ans = magic(arr, size);
    cout << ans << endl;
}