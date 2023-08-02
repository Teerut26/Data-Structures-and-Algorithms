#include <stdio.h>

void move(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("move#%d: move(1, %c, %c)\n", n, source, destination);
        return;
    }

    move(n - 1, source, auxiliary, destination);
    printf("move#%d: move(1, %c, %c)\n", n, source, destination);
    move(n - 1, auxiliary, destination, source);
}

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n <= 0)
        return;

    printf("Start\n");
    printf("tower A:");
    for (int i = 1; i <= n; i++)
        printf(" %d", i);
    printf("\n");
    printf("tower B:\n");
    printf("tower C:\n");

    move(n, source, destination, auxiliary);
}

int main() {
    int n = 2;
    char source = 'A', destination = 'C', auxiliary = 'B';
    towerOfHanoi(n, source, destination, auxiliary);
    return 0;
}
