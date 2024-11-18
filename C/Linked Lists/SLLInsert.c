#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMiddle(struct Node **head, int data, int position) {
    if (*head == NULL || position <= 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
    for (int i = 1; i < position && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *head = NULL;

    // Insert at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);

    // Insert at the end
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);

    // Insert in the middle (after position 2)
    insertAtMiddle(&head, 15, 2);

    printf("Linked list: ");
    displayList(head);

    

    return 0;
}

