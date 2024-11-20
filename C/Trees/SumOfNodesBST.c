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

int sumOfNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int sumOfLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data; // Leaf node
    }
    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
}

int sumOfLeftSubtree(struct Node* root) {
    if (root == NULL || root->left == NULL) {
        return 0;
    }
    return sumOfNodes(root->left);
}

int sumOfRightSubtree(struct Node* root) {
    if (root == NULL || root->right == NULL) {
        return 0;
    }
    return sumOfNodes(root->right);
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL; // Initialize the BST as empty
    int choice, value;

    printf("Binary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Display In-order\n");
    printf("3. Sum of all nodes\n");
    printf("4. Sum of leaf nodes\n");
    printf("5. Sum of left subtree\n");
    printf("6. Sum of right subtree\n");
    printf("7. Exit\n");

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
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Sum of all nodes: %d\n", sumOfNodes(root));
                break;

            case 4:
                printf("Sum of leaf nodes: %d\n", sumOfLeafNodes(root));
                break;

            case 5:
                printf("Sum of nodes in left subtree: %d\n", sumOfLeftSubtree(root));
                break;

            case 6:
                printf("Sum of nodes in right subtree: %d\n", sumOfRightSubtree(root));
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
