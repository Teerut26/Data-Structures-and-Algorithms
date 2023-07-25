#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* createNode(int value) {
    node* temp = malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void insertNode(node** head, node** last, int value) {
    node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        *last = newNode;
    } else if ((*head)->value > value) {
        newNode->next = *head;
        *head = newNode;
    } else if ((*last)->value < value) {
        (*last)->next = newNode;
        *last = newNode;
    } else {
        printList(*head);
        *head = newNode;
        *last = newNode;
    }
}

int main() {
    int SIZE;
    scanf("%d", &SIZE);

    node* head = NULL;
    node* last = NULL;

    int value;
    scanf(" %d", &value);
    insertNode(&head, &last, value);

    for (int i = 1; i < SIZE; i++) {
        scanf(" %d", &value);
        insertNode(&head, &last, value);
    }

    printList(head);

    // Free allocated memory
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
