#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node and make it the root
        return createNode(data);
    }

    if (data < root->data) {
        // If the data is less than the root, insert into the left subtree
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        // If the data is greater than the root, insert into the right subtree
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to print the BST in an in-order traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;  // Initialize the BST as empty

    // Insert nodes into the BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal of the BST:\n");
    inOrderTraversal(root);

    return 0;
}
