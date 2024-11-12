#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if (size <= 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remain = isSorted(arr + 1, size - 1);
        return remain;
    }
}

int main()
{
    int arr[5] = {4, 17, 8, 9, 11};
    int size = 5;

    bool ans = isSorted(arr, size);
    cout << ans << endl;
}