#include <stdio.h>

int ack(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return ack(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return ack(m - 1, ack(m, n - 1));
    }

    return 0;
}

int main()
{
    int result = ack(1,1);
    printf("%d",result);
    return 0;
}