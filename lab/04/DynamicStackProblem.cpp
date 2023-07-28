#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack<int> s;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int n_command;
        cin >> n_command;
        switch (n_command)
        {
        case 1:
            int value;
            cin >> value;
            s.push(value);
            break;
        case 2:
            if (!s.empty())
            {

                s.pop();
            }
            break;
        case 3:
            if (s.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                cout << s.top() << endl;
            }
            break;
        case 4:
            cout << s.size() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}