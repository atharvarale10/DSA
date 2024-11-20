#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root; // Node not found
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data); 
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); 
    } else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            // Case 1: Node has no children
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // Case 2: Node has only a right child
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Case 3: Node has only a left child
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Case 4: Node has two children
            struct Node* temp = findMin(root->right); // Find the minimum node in the right subtree
            root->data = temp->data;                 // Replace with in-order successor
            root->right = deleteNode(root->right, temp->data); // Delete the successor
        }
    }

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;

    int choice, value;

    printf("Binary Search Tree Operations:\n");
    printf("1. Insert\n2. Delete\n3. Display In-order\n4. Display Pre-order\n5. Display Post-order\n6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
