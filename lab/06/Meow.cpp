#include <iostream>
#include <string>

using namespace std;

int checkMeow(string s, int length)
{
    string temp = "";

    for (int i = 0; i < length; i++)
    {
        if (temp == "")
        {
            temp += tolower(s[i]);
        }
        else if (temp[temp.length() - 1] != tolower(s[i]))
        {
            temp += tolower(s[i]);
        }
    }

    if (temp == "meow")
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int length;
        string s;
        cin >> length;
        cin >> s;

        if (checkMeow(s, length))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}