#include <stdio.h>
#include <limits.h>

int main()
{
    int size;
    scanf("%d", &size);
    int matrix[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int maxSum = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int height = 1; height <= size - i; height++)
            {
                for (int width = 1; width <= size - j; width++)
                {
                    int sum = 0;
                    for (int k = i; k < i + height; k++)
                    {
                        for (int l = j; l < j + width; l++)
                        {
                            sum += matrix[k][l];
                        }
                    }
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                    }
                }
            }
        }
    }
    

    printf("%d", maxSum);
    return 0;
}
