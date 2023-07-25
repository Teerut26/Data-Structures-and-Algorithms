// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     string s;
//     getline(cin, s);
//     cout << s << endl;
//     string vowels = "aeiou";

//     for (int i = 0; i < s.length(); i++)
//     {
//         bool isDecode = false;
//         for (int j = 0; j < vowels.length(); j++)
//         {
//             if (s[i] == vowels[j] && s[i + 2] == vowels[j])
//             {
//                 isDecode = true;
//                 break;
//             }
//         }
//         if (isDecode)
//         {
//             cout << s[i];
//             i += 2;
//         }
//         else
//         {
//             cout << s[i];
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    fgets(s, sizeof(s), stdin);

    char vowels[] = "aeiou";

    for (int i = 0; i < strlen(s); i++)
    {
        int isDecode = 0;
        for (int j = 0; j < strlen(vowels); j++)
        {
            if (s[i] == vowels[j] && s[i + 2] == vowels[j])
            {
                isDecode = 1;
                break;
            }
        }
        if (isDecode)
        {
            printf("%c", s[i]);
            i += 2;
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    return 0;
}
