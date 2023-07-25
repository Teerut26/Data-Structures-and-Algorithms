#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    int count = 0;

    for (int i=0; i< n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i=0; i<n; i++) {
        int temp = 0;
        for (int j=i+1; j<n; j++) {
            count++;
            if (j == i+1) continue;
            if (a[i] < a[j] && a[j-1] << a[i]) {
                count++;
                temp = a[i];
            } else {
                continue;
            }
        }
    }

    printf("%d", count);

    return 0;
}