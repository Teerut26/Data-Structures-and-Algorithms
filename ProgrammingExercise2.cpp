#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string name;
    int size;
    int type;
    int total_size;
    Node *parent;
    Node *firstChild;
    Node *nextSibling;

    Node(const string &name, int type, int size, Node *parent)
        : name(name), size(size), type(type), total_size(size), parent(parent), firstChild(nullptr), nextSibling(nullptr) {}

    void addChild(Node *child)
    {
        if (firstChild == nullptr)
        {
            firstChild = child;
        }
        else
        {
            Node *currentSibling = firstChild;
            while (currentSibling->nextSibling != nullptr)
            {
                currentSibling = currentSibling->nextSibling;
            }
            currentSibling->nextSibling = child;
        }
    }
};

void printTree(Node *node, int depth)
{
    if (node == nullptr)
        return;

    for (int i = 0; i < depth; i++)
    {
        cout << "  ";
    }

    if (node->type == 1)
    {
        cout << "Folder: " << node->name << ", Total Size: " << node->total_size / 1000 << "K" << endl;
    }
    else
    {
        cout << "File: " << node->name << ", Size: " << node->size / 1000 << "K" << endl;
    }

    printTree(node->firstChild, depth + 1);
    printTree(node->nextSibling, depth);
}

int updateTotalSize(Node *node)
{
    if (node == nullptr)
        return 0;

    int total = node->size;
    total += updateTotalSize(node->firstChild);
    total += updateTotalSize(node->nextSibling);

    if (node->parent != nullptr)
    {
        node->parent->total_size += total;
    }

    return total;
}

int main()
{
    Node *root = new Node("root/", 1, 0, nullptr);
    Node *folder1 = new Node("folder1/", 1, 0, root);
    Node *file1 = new Node("file1", 0, 2000, folder1);
    Node *folder2 = new Node("folder2/", 1, 0, root);
    Node *file2 = new Node("file2", 0, 3000, folder2);
    Node *file3 = new Node("file3", 0, 4000, folder2);

    updateTotalSize(root);
    cout << "Directory Structure:" << endl;
    printTree(root, 0);

    // Clean up memory
    delete root;
    delete folder1;
    delete folder2;
    delete file1;
    delete file2;
    delete file3;

    return 0;
}
