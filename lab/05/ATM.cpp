#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> queue_index;

    int n, x;
    cin >> n >> x;
    int deposit_values[n];

    for (int i = 1; i <= n; i++)
    {
        int a_temp = 0;
        cin >> a_temp;
        deposit_values[i] = a_temp;
        queue_index.push(i);
    }

    int i = 1;
    while (1)
    {
        if (queue_index.empty())
        {
            break;
        }

        int deposit_value = deposit_values[queue_index.front()];

        if (deposit_value <= x)
        {
            cout << queue_index.front() << " ";
            queue_index.pop();
        }
        else if (deposit_value > x)
        {
            deposit_values[queue_index.front()] -= x;
            queue_index.push(queue_index.front());
            queue_index.pop();
        }

    }

    return 0;
}
