#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *data;
    int top;
    int size;
} stack;

int n;
int move_num = 1;
stack *A;
stack *B;
stack *C;

stack *createStack(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
    return s;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

void push(stack *s, int x)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    int x = s->data[s->top];
    s->top--;
    return x;
}

void printStack(stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void printTower()
{
    printf("tower A: ");
    printStack(A);
    printf("tower B: ");
    printStack(B);
    printf("tower C: ");
    printStack(C);
}

void move(stack *A, stack *B, char from, char to)
{
    int x = pop(A);
    push(B, x);
    printf("move #%d: move(%d,%c,%c)\n", move_num++, x, from, to);
}

void towerOfHanoi(int n, stack *A, stack *B, stack *C, char from, char aux, char to)
{
    if (n == 1)
    {
        move(A, C, from, to);
        printTower();
    }
    else
    {
        towerOfHanoi(n - 1, A, C, B, from, to, aux);
        move(A, C, from, to);
        printTower();
        towerOfHanoi(n - 1, B, A, C, aux, from, to);
    }
}

int main()
{
    printf("input N = ");
    scanf("%d", &n);

    A = createStack(n);
    B = createStack(n);
    C = createStack(n);

    for (int i = n; i >= 1; i--)
    {
        push(A, i);
    }

    printf("Output:\n");
    printf("Start of program.\n\n");

    printTower();

    towerOfHanoi(n, A, B, C, 'A', 'B', 'C');

    printf("\nEnd of program.\n");
}