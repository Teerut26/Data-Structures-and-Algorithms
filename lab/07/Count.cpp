#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int data[n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    int target;
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        if (target == data[i])
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}