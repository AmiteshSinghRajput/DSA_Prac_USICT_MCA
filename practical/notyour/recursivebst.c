#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
}*root = NULL ;
struct node *insert(struct node *p,int data)
{
    struct node *t = NULL;
    if(p==NULL)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data = data;
            t->left=t->right=NULL;
            return t;
        }
    if(data > p->data)
        p->right=insert(p->right,data);
    else if(data < p->data)
        p->left=insert(p->left,data);

    return p;
}
void preorder(struct node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(struct node *p)
{
    if(p)
    {

        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}
struct node *search(int data)
{
    struct node *temp = root;
    while(temp!=NULL)
    {
        if(data == temp->data)
            return temp;
        else if(data<temp->data)
            temp=temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}
int height(struct node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->left);
    y=height(p->right);
    return x>y? x+1 : y+1 ;
}
struct node *InPre(struct node *p)
{
    while(p && p->right!=NULL)
        p=p->right;
    return p;
}
struct node *InSucc(struct node *p)
{
    while(p && p->left != NULL)
        p=p->left;
    return p;
}
struct node *Delete(struct node *p,int data)
{
    struct node *temp,*t;
    t=search(data);
    if(t==NULL){
        printf("Element not found");
        return NULL;
    }
    if(p==NULL)
        return NULL;
    if(p->left == NULL && p->right == NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(data < p->data)
        p-> left = Delete(p->left,data);
    else if(data > p->data)
        p-> right = Delete(p->right,data);
    else if(data == p->data){
        if(height(p->left)>height(p->right))
        {
            temp=InPre(p->left);
            p->data = temp -> data;
            p->left = Delete(p->left,temp->data);
        }
        else{
            temp=InSucc(p->right);
            p->data = temp -> data;
            p->right = Delete(p->right,temp->data);
        }
    }
    return p;
}
int main()
{
    int choice,data;
    struct node *temp;
    do
    {
        printf("Operation on binary search tree are : \n");
        printf("1.Insertion \n2.Deletion \n3.Search \n");
        printf("4.Inorder traversal\n5.Postorder traversal\n6.Preorder traversal\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data you want to insert\n");
            scanf("%d", &data);
            if (root == NULL)
                root = insert(root, data);
            else
                insert(root, data);
            break;
        case 2:
            printf("Enter data you want to delete\n");
            scanf("%d", &data);
            Delete (root, data);
            break;
        case 3:
            printf("enter data you want to search\n");
            scanf("%d", &data);
            temp = search(data);
            if(temp!=NULL)
                printf("\nElement %d is found \n",temp->data);
            else
                printf("\nElement not found\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            postorder(root);
            printf("\n");
            break;
        case 6:
            preorder(root);
            printf("\n");
            break;
        case 7:
            printf("Exiting...");
            return 0;
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (choice != 7);
    return 0;
}
