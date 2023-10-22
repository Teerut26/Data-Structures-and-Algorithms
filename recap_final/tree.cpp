#include <iostream>

using namespace std;

typedef struct node_
{
    int key;
    int total_size;
    struct node_ *parent;
    struct node_ *leftChild;
    struct node_ *rightSibling;
} Node;

Node *createRoot(int key)
{
    Node *root = (Node *)calloc(sizeof(Node), 1);
    root->key = key;
    return root;
}

Node *createNode(Node *parent, int key)
{
    Node *node = (Node *)calloc(sizeof(Node), 1);
    node->parent = parent;
    node->key = key;

    if (parent->leftChild == NULL)
    {
        parent->leftChild = node;
    }
    else
    {
        Node *current = parent->leftChild;
        while (current->rightSibling != NULL)
        {
            current = current->rightSibling;
        }
        current->rightSibling = node;
    }
    return node;
}

Node *getParent(Node *node)
{
    return node->parent;
}

Node *getChild(Node *node, int k)
{
    Node *current = node->leftChild;
    for (int i = 1; i < k; i++)
    {
        current->rightSibling = current;
    }
    return current;
}

bool isRoot(Node *node)
{
    return node->parent == NULL;
}

bool isExternal(Node *node)
{
    return node->leftChild == NULL;
}

int getDept(Node *node)
{
    Node *current = node;
    int dept = 0;
    while (current->parent != NULL)
    {
        current = current->parent;
        dept++;
    }
    return dept;
}

void preorder(Node *node)
{
    Node *current = node->leftChild;
    cout << node->key;
    while (current != NULL)
    {
        preorder(current);
        current = current->rightSibling;
    }
}
void postorder(Node *node)
{
    Node *current = node->leftChild;
    while (current != NULL)
    {
        postorder(current);
        current = current->rightSibling;
    }
    cout << node->total_size << " ";
}

void addsignSizeToNode(Node *node)
{
    Node *current = node->leftChild;

    while (current != NULL)
    {
        addsignSizeToNode(current);
        current = current->rightSibling;
    }

    if (isExternal(node))
    {
        node->total_size = node->key;
    }
    else
    {
        int total_temp = 0;
        Node *current2 = node->leftChild;
        while (current2 != NULL)
        {
            total_temp += current2->total_size;
            current2 = current2->rightSibling;
        }

        node->total_size = node->key + total_temp;
    }
}

int main()
{
    Node *root = createRoot(0);
    Node *node1 = createNode(root, 1);
    Node *node2 = createNode(root, 2);
    Node *node3 = createNode(root, 3);
    Node *node4 = createNode(node1, 4);
    Node *node5 = createNode(node1, 5);
    Node *node6 = createNode(node2, 6);
    Node *node7 = createNode(node2, 7);
    Node *node8 = createNode(node3, 8);
    Node *node9 = createNode(node3, 9);

    // preorder(root);
    // cout << endl;
    addsignSizeToNode(root);
    // cout << root->total_size;
    postorder(root);

    return 0;
}