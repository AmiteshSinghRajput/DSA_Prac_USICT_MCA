#include<stdio.h>
#include<stdlib.h>
int arr[10];
int size=-1;
void display()
{
    if(size==-1)
    {
        printf("Array is empty");
    }
    else{
        printf("Array is:- ");
        for(int i=0;i<=size;i++)
        {
            printf("%d,",arr[i]);
        }
        printf("END\n");
    }
}
int search(int loc)
{
    int cv=0,i;
    for(i=0;i<=size;i++)
    {
        if(arr[i]==loc)
        {
            cv++;
            break;
        }
    }
    if(cv==1)
        return i;
    else
        return -1;
}
void add_at_beg(int n)
{
    if(size==9)
        printf("array is full\n");
    else if(size==-1)
        add_at_end(n);
    else{

        for(int i=size;i>=0;i--)
            arr[i+1]=arr[i];
        arr[0]=n;
        size++;
    }
}
void add_at_end(int n)
{
    if(size==9)
    {
        printf("Array is full \n");
    }
    else
    {
        size++;
        arr[size]=n;
    }
}
void add_at_loc(int loc,int n)
{
    if(size==9)
    {
        printf("Array is full");
    }
    else{
        int j,index = search(loc);
        if(index==-1)
            printf("Element not found");
        else
        {
            if(index==size)
                add_at_end(n);
            else
            {
                for(j=size;j>index;j--)
                {
                    arr[j+1]=arr[j];
                }
                arr[j+1]=n;
                size++;
            }
        }
    }
}
void del_beg()
{
    if(size==-1)
        printf("Nothing to delete\n");
    else{
        printf("Deleted element is : ");
        printf("%d \n",arr[0]);
        for(int i=0;i<=size;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
}
void del_end()
{
    if(size==-1)
        printf("Nothing to delete \n");
    else
    {
        printf("Deleted element is : ");
        printf("%d \n",arr[size]);
        size--;
    }
}
void del_specific(int loc)
{
    if(size==-1)
        printf("Nothing to delete \n");
    else
    {
        int i=search(loc);
        if(i==-1)
            printf("Element not found\n");
        else
        {
            int j;
            printf("Deleted element is : ");
            printf("%d \n",arr[i]);
            for(j=i;j<size;j++)
                arr[j]=arr[j+1];
            size--;
        }
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort()
{
    if(size==-1)
        printf("Array is Empty");
    else{
    int i, j, min;
    for (i = 0; i < size; i++)
    {
        min = i;
        for (j = i+1; j < size+1; j++)
          if (arr[j] < arr[min])
            min = j;
          if(min!= i)
            swap(&arr[min], &arr[i]);
    }
    printf("Sorted ");
    display();
    }
}
void main()
{
    int a,i=0,c1,loc,s;
    do{
        printf("1.Insert at beginning \n");
        printf("2.Insert at end \n");
        printf("3.Insert at location \n");
        printf("4.Delete at beginning \n");
        printf("5.Delete at end \n");
        printf("6.Delete specific element \n");
        printf("7.Search element \n");
        printf("8.Selection sort \n");
        printf("9.Display \n");
        printf("10.Exit \n");
        printf("Enter Choice\n");
        scanf("%d",&c1);
        switch(c1)
        {
        case 1:
            printf("Enter array element \n");
            scanf("%d",&a);
            add_at_beg(a);
            break;
        case 2:
            printf("Enter array element \n");
            scanf("%d",&a);
            add_at_end(a);
            break;
        case 3:
            printf("Enter array element \n");
            scanf("%d",&a);
            printf("Enter location after which element has to be added \n");
            scanf("%d",&loc);
            add_at_loc(loc,a);
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            printf("Enter element to be deleted \n");
            scanf("%d",&loc);
            del_specific(loc);
            break;
        case 7:
            printf("Enter element to be searched \n");
            scanf("%d",&loc);
            s=search(loc);
            if(s==-1)
                printf("Element not found\n");
            else
                {
                    printf("Element found at index :- ");
                    printf("%d \n",s);
                }
            break;
        case 8:
            selectionSort();
            break;
        case 9:
            display();
            break;
        case 10:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice \n");
            break;
        }
    }while(c1!=10);
}
