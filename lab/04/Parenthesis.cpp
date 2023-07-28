#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool isCorrect = true;

    if (s[0] == ')')
    {
        isCorrect = false;
    }
    else
    {
        int open = 0;
        int close = 0;
        for (int i = 0; i < s.length(); i++)
        {
            s[i] == '(' ? open++ : close++;
        }
        isCorrect = (open == close);
    }

    if (isCorrect)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}