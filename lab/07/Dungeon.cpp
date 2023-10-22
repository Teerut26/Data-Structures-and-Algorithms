#include <iostream>

using namespace std;

int main()
{
    int n_monsters;
    cin >> n_monsters;
    int monsters[n_monsters];
    
    for (int i = 0; i < n_monsters; i++)
    {
        cin >> monsters[i];
    }

    int n_weapons;
    cin >> n_weapons;
    
    for (int i = 0; i < n_weapons; i++)
    {
        int weapon_power;
        cin >> weapon_power;
        
        int count = 0;
        
        for (int j = 0; j < n_monsters; j++)
        {
            if (monsters[j] <= weapon_power)
            {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    
    

    return 0;
}