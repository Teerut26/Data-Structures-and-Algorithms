#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[100];
    int size;
    int type;
    int total_size;
    struct node *parent;
    struct node *firstChild;
    struct node *nextSibling;
};

typedef struct node Node;
typedef Node *NodePtr;

NodePtr createNode(char name[100], int type, int size, NodePtr parent)
{
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->size = size;
    node->type = type;
    node->total_size = size;
    node->parent = parent;
    node->firstChild = NULL;
    node->nextSibling = NULL;

    if (parent != NULL)
    {
        if (parent->firstChild == NULL)
        {
            parent->firstChild = node;
        }
        else
        {
            NodePtr currentSibling = parent->firstChild;
            while (currentSibling->nextSibling != NULL)
            {
                currentSibling = currentSibling->nextSibling;
            }
            currentSibling->nextSibling = node;
        }
    }
    return node;
}
void printTraverse(NodePtr root)
{
    if (root == NULL)
        return;

    if (root->type == 1)
    {
        printf("Name: %s ,total size: %d\n", root->name, root->total_size);
    }

    printTraverse(root->firstChild);
    printTraverse(root->nextSibling);
}

void updateTotalSize(NodePtr node)
{
    if (node == NULL)
    {
        return;
    }

    updateTotalSize(node->firstChild);
    updateTotalSize(node->nextSibling);

    if (node->parent != NULL)
    {
        node->parent->total_size += node->total_size;
    }
}

int main()
{
    NodePtr root = createNode("/user/rt/courses/", 1, 1000, NULL);
    NodePtr cs016 = createNode("cs016/", 1, 2000, root);
    NodePtr grades1 = createNode("grades", 0, 8000, cs016);

    NodePtr homeworks = createNode("homeworks/", 1, 1000, cs016);
    NodePtr hw1 = createNode("hw1", 0, 3000, homeworks);
    NodePtr hw2 = createNode("hw2", 0, 2000, homeworks);
    NodePtr hw3 = createNode("hw3", 0, 4000, homeworks);

    NodePtr programs = createNode("programs/", 1, 1000, cs016);
    NodePtr pr1 = createNode("pr1", 0, 57000, programs);
    NodePtr pr2 = createNode("pr2", 0, 97000, programs);
    NodePtr pr3 = createNode("pr3", 0, 74000, programs);

    NodePtr cs252 = createNode("cs252/", 1, 1000, root);
    NodePtr projects = createNode("projects/", 1, 1000, cs252);
    NodePtr grades2 = createNode("grades", 0, 3000, cs252);
    NodePtr papers = createNode("papers/", 1, 1000, projects);
    NodePtr demos = createNode("demos/", 1, 1000, projects);
    NodePtr buylow = createNode("buylow", 0, 26000, papers);
    NodePtr sellhigh = createNode("sellhigh", 0, 55000, papers);
    NodePtr market = createNode("market", 0, 4786000, demos);

    updateTotalSize(root);
    printTraverse(root);

    return 0;
}
