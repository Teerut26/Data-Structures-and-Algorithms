#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> queue_value;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int command;
        cin >> command;
        switch (command)
        {
        case 1:
            int value;
            cin >> value;
            queue_value.push(value);
            break;
        case 2:
            if (!queue_value.empty())
            {
                queue_value.pop();
            }
            break;
        case 3:
            if (!queue_value.empty())
            {
                cout << queue_value.front() << endl;
            }
            else
            {
                cout << "EMPTY" << endl;
            }
            break;
        case 4:
            cout << queue_value.size() << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}