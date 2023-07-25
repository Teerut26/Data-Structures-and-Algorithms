#include <iostream>

using namespace std;

int main()
{
    int n_rows, n_cols;
    cin >> n_rows >> n_cols;

    int martix[n_rows][n_cols];

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            cin >> martix[i][j];
        }
    }

    bool is_first = false;
    int list[n_cols];
    for (int i = 0; i < n_rows; i++)
    {
        if (!is_first)
        {
            for (int j = 0; j < n_cols; j++)
            {
                list[j] = martix[i][j] - 1;
            }
            is_first = true;
        }
        else
        {
            for (int j = 0; j < n_cols; j++)
            {
                list[j] = martix[i][list[j]] - 1;
            }
        }
    }

    for (int i = 0; i < n_cols; i++)
    {
        cout << list[i] + 1 << " ";
    }

    return 0;
}