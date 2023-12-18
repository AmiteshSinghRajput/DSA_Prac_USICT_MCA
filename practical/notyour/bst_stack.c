#include <stdlib.h>
#include <stdio.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
struct node *stack[100];

int tos = -1;
void *create(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void *insert(struct node *root, int data)
{

    if (root == NULL)
    {
        return create(data);
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}
void preorder(struct node *root)
{
    stack[++tos] = NULL;
    while (root != NULL)
    {
        printf("%d ", root->data);
        if (root->right != NULL)
        {
            stack[++tos] = root->right;
        }
        if (root->left == NULL)
        {
            root = stack[tos--];
        }

        else
        {
            root = root->left;
        }
    }
}
void inorder(struct node *root)
{
    while (root != NULL || tos != -1)
    {
        while (root != NULL)
        {
            stack[++tos] = root;
            root = root->left;
        }

        if (tos != -1)
        {
            root = stack[tos--];
            printf("%d ", root->data);
            root = root->right;
        }
    }
}
void postorder(struct node *root)
{
    while (root != NULL || tos != -1)
    {
        while (root != NULL)
        {
            if (root->right != NULL)
            {
                stack[++tos] = root->right;
            }
            stack[++tos] = root;
            root = root->left;
        }

        root = stack[tos--];

        if (root->right != NULL && stack[tos] == root->right)
        {
            stack[tos--];
            stack[++tos] = root;
            root = root->right;
        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    }
}

int main()
{
    int choice;
    int data;
    struct node *root = NULL;
    do
    {
        printf("Operations on binary search tree\n");
        printf("1.Insert \n2.Preorder traversal \n");
        printf("3.Inorder traversal\n");
        printf("4.Postorder traversal \n5.Exit\n");
        printf("enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter data you wannt to insert\n");
            scanf("%d", &data);
            if (root == NULL)
            {
                root = insert(root, data);
            }
            else
            {
                insert(root, data);
            }
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting...");
            return 0;
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice !=5);
   return 0;
}
