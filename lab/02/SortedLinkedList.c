#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef Node *NodePtr;

void addNode(NodePtr *headNode, int value)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    if (*headNode == NULL)
    {
        *headNode = tmp;
    }
    else
    {
        Node *current = *headNode;
        Node *prev = NULL;
        while (current != NULL)
        {
            if (current->value > value)
            {
                break;
            }
            prev = current;
            current = current->next;
        }
        if (prev == NULL)
        {
            tmp->next = *headNode;
            *headNode = tmp;
        }
        else
        {
            prev->next = tmp;
            tmp->next = current;
        }
    }
}

void printList(NodePtr *head)
{
    Node *current = *head;

    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main()
{
    Node *head = NULL;

    while (1)
    {
        int value;
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        addNode(&head, value);
    }
    printList(&head);
}