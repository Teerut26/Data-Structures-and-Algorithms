#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int min = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        int n_temp = 0;
        scanf("\n%d", &n_temp);

        if (min == 0)
        {
            min = n_temp;
        }
        else if (n_temp <= min)
        {
            min = n_temp;
        }

        if (max == 0) {
            max = n_temp;
        }else if (n_temp >= max) 
        {
            max = n_temp;
        }
        
    }

    printf("%d\n",min);
    printf("%d",max);
    return 0;
}