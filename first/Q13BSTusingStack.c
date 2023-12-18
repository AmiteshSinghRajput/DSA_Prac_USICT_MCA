#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};

struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct StackNode* createStackNode(struct TreeNode* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = node;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, struct TreeNode* node) {
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = *root;
    *root = stackNode;
}

struct TreeNode* pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        return NULL;
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct TreeNode* popped = temp->data;
    free(temp);
    return popped;
}

void iterativeInorder(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct StackNode* stack = NULL;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void iterativePreorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    struct StackNode* stack = NULL;
    push(&stack, root);
    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);
        if (current->right) {
            push(&stack, current->right);
        }
        if (current->left) {
            push(&stack, current->left);
        }
    }
}

void iterativePostorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);
    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);
        if (current->left) {
            push(&stack1, current->left);
        }
        if (current->right) {
            push(&stack1, current->right);
        }
    }
    while (!isEmpty(stack2)) {
        struct TreeNode* current = pop(&stack2);
        printf("%d ", current->data);
    }
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createTreeNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
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
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int displayMainMenu() {
    int choice;
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Search \n");
    printf("4. Inorder Traversal \n");
    printf("5. Preorder Traversal \n");
    printf("6. Postorder Traversal \n");
    printf("7. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct TreeNode* root = NULL;
    int mainChoice, value;
    do {
        mainChoice = displayMainMenu();
        switch (mainChoice) {
        case 1:
            printf("Enter the value to insert into BST: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value to delete from BST: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printf("Enter the value to search in BST: ");
            scanf("%d", &value);
            if (search(root, value)) {
                printf("%d is present in the BST.\n", value);
            } else {
                printf("%d is not present in the BST.\n", value);
            }
            break;
        case 4:
            printf("Inorder Traversal: ");
            iterativeInorder(root);
            printf("\n");
            break;
        case 5:
            printf("Preorder Traversal: ");
            iterativePreorder(root);
            printf("\n");
            break;
        case 6:
            printf("Postorder Traversal: ");
            iterativePostorder(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (mainChoice != 7);
    return 0;
}
