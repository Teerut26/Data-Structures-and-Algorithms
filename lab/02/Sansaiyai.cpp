#include <iostream>

struct Node {
    int left;
    int right;
};

int main() {
    int n;
    std::cin >> n;

    Node* students = new Node[n];

    for (int i = 0; i < n; i++) {
        std::cin >> students[i].left >> students[i].right;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (students[i].left == 0 && students[i].right != 0) {
            int tempCount = 2;
            int hand = students[i].right;
            while (students[hand - 1].right != 0) {
                tempCount++;
                hand = students[hand - 1].right;
            }
            count = std::max(count, tempCount);
        }
    }

    std::cout << (count == 0 ? 1 : count) << std::endl;

    delete[] students; // Don't forget to free the memory

    return 0;
}
