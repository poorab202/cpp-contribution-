#include <stdio.h>

void multiply(int a[3][3], int b[3][3])
{
    int result[3][3];
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k <= 2; k++)
            {
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("\narray 1:\n");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("array 2:\n");

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("%d  ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Resultant array:\n");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("%d  ", result[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int array_1[3][3], array_2[3][3];
    printf("Enter values for 1st matrix:\n\n");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("Enter value of a[%d][%d]:", i, j);
            scanf("%d", &array_1[i][j]);
        }
    }
    printf("\n\nEnter values for 1st matrix:\n\n");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("Enter value of a[%d][%d]:", i, j);
            scanf("%d", &array_2[i][j]);
        }
    }
    multiply(array_1, array_2);
}
