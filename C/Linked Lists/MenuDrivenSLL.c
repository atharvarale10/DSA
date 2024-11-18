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

void insertAtStart(struct node **head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
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

void insertAtMiddle(struct node **head, int data, int position) {
    if (*head == NULL || position <= 1) {
        insertAtStart(head, data);
        return;
    }
    struct node *newNode = createNode(data);
    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtStart(struct node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
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
    free(temp->next);
    temp->next = NULL;
}

void deleteAtMiddle(struct node **head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (position == 1) {
        deleteAtStart(head);
        return;
    }
    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct node *delete = temp->next;
    temp->next = temp->next->next;
    free(delete);
}

void reverseList(struct node **head) {
    struct node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
    struct node *head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at start\n");
        printf("2. Insert at middle\n");
        printf("3. Insert at end\n");
        printf("4. Delete at start\n");
        printf("5. Delete at middle\n");
        printf("6. Delete at end\n");
        printf("7. Reverse list\n");
        printf("8. Count nodes\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtMiddle(&head, data, position);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 4:
                deleteAtStart(&head);
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtMiddle(&head, position);
                break;

            case 6:
                deleteAtEnd(&head);
                break;

            case 7:
                reverseList(&head);
                printf("List reversed.\n");
                break;

            case 8:
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 9:
                displayList(head);
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);

   
    return 0;
}
