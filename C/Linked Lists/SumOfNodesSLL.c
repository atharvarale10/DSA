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

int sumOfNodes(struct node *head) {
    int sum = 0;
    struct node *temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
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
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Display the list\n");
        printf("3. Calculate the sum of nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 2:
                printf("Linked list: ");
                displayList(head);
                break;

            case 3:
                printf("Sum of nodes: %d\n", sumOfNodes(head));
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);


    return 0;
}
