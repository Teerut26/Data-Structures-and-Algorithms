#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct NodeHead
{
    int value;
    struct Node *next;
} NodeHead;

typedef Node *NodePtr;

int main()
{
    NodePtr head = NULL;

    NodePtr node1 = (NodePtr)malloc(sizeof(Node));
    NodePtr node2 = (NodePtr)malloc(sizeof(Node));

    node1->value = 1;
    node2->value = 2;

    node1->next = node2;
    node2->next = NULL;

    head = node2;
}