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

void insertAtEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct node* concatenateLists(struct node *head1, struct node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    struct node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
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
    struct node *list1 = NULL, *list2 = NULL;
    int choice, data;

    printf("Creating first linked list:\n");
    do {
        printf("Enter data (or -1 to stop): ");
        scanf("%d", &data);
        if (data != -1) {
            insertAtEnd(&list1, data);
        }
    } while (data != -1);

    printf("Creating second linked list:\n");
    do {
        printf("Enter data (or -1 to stop): ");
        scanf("%d", &data);
        if (data != -1) {
            insertAtEnd(&list2, data);
        }
    } while (data != -1);

    printf("\nFirst linked list: ");
    displayList(list1);

    printf("Second linked list: ");
    displayList(list2);

    // Concatenate the two linked lists
    list1 = concatenateLists(list1, list2);

    printf("\nConcatenated linked list: ");
    displayList(list1);


    return 0;
}
