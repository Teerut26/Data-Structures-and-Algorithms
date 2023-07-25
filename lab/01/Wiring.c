#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int h[n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int isStart = 0;

        for (int j = i + 1; j < n; j++)
        {
            if (isStart == 0)
            {
                isStart++;
                count+=1;
                continue;
            }
            
            int canlink = 0;

            for (int k = i + 1; k < j; k++)
            {
                if (h[i] > h[k] && h[k] < h[j])
                {
                    canlink = 1;
                }
                else
                {
                    canlink = 0;
                    break;
                }
            }
            if (canlink)
            {
                count += 1;
            }
        }
    }

    printf("%d", count);

    return 0;
}