#include <stdio.h>

int main()
{
    int m;
    printf("\nEnter The Number of Rows of Sparse Matrix:\n");

    scanf("%d", &m);
    int n;
    printf("\nEnter The Number of Columns of Sparse Matrix:\n");
    scanf("%d", &n);

    int arr[m][n], count = 0;
    printf("\nEnter The Elements In the Sparse Matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    if (count < (((m * n) / 2) + 1))
    {
        printf("\nEntered Matrix Is Not A Sparse Matrix :(\n");
        return 1;
    }

    printf("\nEntered Sparse Matrix is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    int col = 3;
    int row = ((m * n) - count) + 1;
    int res[row][col];
    res[0][0] = m;
    res[0][1] = n;
    res[0][2] = (m * n) - count;
    int cnt=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
          if(arr[i][j]!=0)
          {
            cnt++;
            res[cnt][0]=i;
            res[cnt][1]=j;
            res[cnt][2]=arr[i][j];

          }
        }
    }

    printf("\nReduced Matrix of Given Sparse Matrix Is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }


    return 0;
}