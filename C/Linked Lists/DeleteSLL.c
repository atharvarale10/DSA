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

void deleteStart(struct node **head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct node **head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    struct node *temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct node *last = temp->next;
    temp->next = NULL;
    free(last);
}

void deleteMid(struct node **head, int pos) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    struct node *temp = *head;

    if (pos == 1) {
        deleteStart(head);
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct node *delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
}


int main() {
    struct node *head = NULL;
    struct node *temp = NULL;

    head = createNode(10);
    temp = head;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(30);
    temp = temp->next;
    temp->next = createNode(40);
    temp = temp->next;
    temp->next = createNode(50);

    printf("Initial linked list: ");
    displayList(head);

    // Delete the first node
    printf("\nDeleting the first node...\n");
    deleteStart(&head);
    displayList(head);

    // Delete the last node
    printf("\nDeleting the last node...\n");
    deleteEnd(&head);
    displayList(head);

    // Delete a node at position 2
    printf("\nDeleting the node at position 2...\n");
    deleteMid(&head, 2);
    displayList(head);
  
    return 0;
}
