#include <stdio.h>

int a(int n, int sum) {
    if (n == 1) {
        return sum;
    } else {
        return a(n - 1, sum + 3);
    }
}

int linearRecursion(int n) {
    // Base case: when n is 1, return the value of a1 (2 in this case)
    if (n == 1) {
        return 2;
    }
    // Recursive case: calculate an-1 + 3 and return the result
    else {
        return linearRecursion(n - 1) + 3;
    }
}

int main()
{
    int result = linearRecursion(5);
    printf("%d",result);
    return 0;
}