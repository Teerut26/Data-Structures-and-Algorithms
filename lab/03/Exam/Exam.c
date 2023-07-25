#include <stdio.h>

double avgCal(int (*score)[3], int n, int col)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += score[i][col];
    }
    return sum / n;
}

int main()
{
    int n;
    scanf("%d", &n);
    int score[n][3];

    double avg[3];
    double avgSum;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
    }

    avg[0] = avgCal(score, n, 0);
    avg[1] = avgCal(score, n, 1);
    avg[2] = avgCal(score, n, 2);

    avgSum = (avg[0] + avg[1] + avg[2]);

    for (int i = 0; i < n; i++)
    {
        int sum = score[i][0] + score[i][1] + score[i][2];

        if ((score[i][0] <= 0 || score[i][1] <= 0 || score[i][2] <= 0) || (score[i][0] > 100 || score[i][1] > 100 || score[i][2] > 100))
        {
            continue;
        }
        else
        {
            if ((score[i][0] >= avg[0] && score[i][1] >= avg[1]) || (score[i][0] >= avg[0] && score[i][2] >= avg[2]) || (score[i][1] >= avg[1] && score[i][2] >= avg[2]) || (score[i][0] >= avg[0] && score[i][1] >= avg[1] && score[i][2] >= avg[2]))
            {

                if (sum > avgSum)
                {
                    printf("%d ", i + 1);
                }
            }
        }
    }

    return 0;
}