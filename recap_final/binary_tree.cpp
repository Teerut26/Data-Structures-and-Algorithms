#include <iostream>

using namespace std;

typedef struct binary_tree
{
    int key;
    struct binary_tree *parent;
    struct binary_tree *leftChild;
    struct binary_tree *rightCild;

} Node;

Node *createRoot(int key)
{
    Node *binary_tree = (Node *)calloc(sizeof(Node), 1);
    binary_tree->key = key;
    return binary_tree;
}

Node *createRight(Node *parent, int key)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->key = key;
    newNode->parent = parent;
    parent->rightCild = newNode;
    return newNode;
}

Node *createLeft(Node *parent, int key)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->key = key;
    newNode->parent = parent;
    parent->leftChild = newNode;
    return newNode;
}

bool isExternal(Node *node)
{
    return node->leftChild == NULL && node->rightCild == NULL;
}

int getDept(Node *node)
{
    Node *current = node->parent;
    int dept = 0;
    while (current != NULL)
    {
        current = current->parent;
        dept++;
    }
    return dept;
}

void preorder(Node *node)
{
    cout << node->key << " ";
    if (node->leftChild != NULL)
    {
        preorder(node->leftChild);
    }

    if (node->rightCild != NULL)
    {
        preorder(node->rightCild);
    }
}

void postorder(Node *node)
{
    if (node->leftChild != NULL)
    {
        postorder(node->leftChild);
    }

    if (node->rightCild != NULL)
    {
        postorder(node->rightCild);
    }
     cout << node->key << " ";
}

void inorder(Node *node)
{
    if (node->leftChild != NULL)
    {
        inorder(node->leftChild);
    }

    cout << node->key << " ";

    if (node->rightCild != NULL)
    {
        inorder(node->rightCild);
    }
}

int main()
{
    Node *root = createRoot(20);
    Node *node1 = createLeft(root, 10);
    Node *node2 = createRight(root, 5);
    Node *node3 = createLeft(node1, 10);
    Node *node4 = createRight(node2, 5);
    Node *node5 = createLeft(node2, 1);

    // cout << getDept(node3);
    // preorder(root);
    // postorder(root);
    inorder(root);

    return 0;
}