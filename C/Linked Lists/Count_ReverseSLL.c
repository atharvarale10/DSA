#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev one step forward
        current = next;        // Move current one step forward
    }

    return prev;  // New head of the reversed list
}

int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void displayList(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL, *temp = NULL;

    head = createNode(10);
    temp = head;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(30);
    temp = temp->next;
    temp->next = createNode(40);
    temp = temp->next;
    temp->next = createNode(50);

    printf("Original linked list: ");
    displayList(head);

    // Count the nodes in the list
    int count = countNodes(head);
    printf("Number of nodes in the list: %d\n", count);

    // Reverse the linked list
    head = reverseList(head);
    printf("Reversed linked list: ");
    displayList(head);


    return 0;
}
