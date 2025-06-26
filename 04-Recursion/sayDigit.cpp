#include <iostream>
using namespace std;

void magic(int n)
{
    string name[10] = {
        "Zero ",
        "One ",
        "Two ",
        "Three ",
        "Four ",
        "Five ",
        "Six ",
        "Seven ",
        "Eight ",
        "Nine "};

    if (n == 0)
    {
        return;
    }
    magic(n / 10);
    cout << name[n % 10];
}

int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    magic(n);
}