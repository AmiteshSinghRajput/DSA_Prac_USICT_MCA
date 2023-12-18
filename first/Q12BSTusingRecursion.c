#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createTreeNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct TreeNode* insertNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createTreeNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct TreeNode* findMinValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a value from the BST
struct TreeNode* deleteTreeNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteTreeNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteTreeNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMinValueNode(root->right);
        root->key = temp->key;
        root->right = deleteTreeNode(root->right, temp->key);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Function to operate on Binary Search Tree
void operateOnBST() {
    struct TreeNode* root = NULL;
    int value, choice;

    do {
        printf(" Operations on Binary Search Tree    \n");
        printf("1. Insert                            \n");
        printf("2. Delete                            \n");
        printf("3. Inorder Traversal                 \n");
        printf("4. Preorder Traversal                \n");
        printf("5. Postorder Traversal               \n");
        printf("6. Back to Main Menu                 \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteTreeNode(root, value);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 6:
            // Back to the main menu
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
}

// Driver program
int main() {
    operateOnBST();
    return 0;
}
