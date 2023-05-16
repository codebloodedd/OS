// Banker's algo
#include <stdio.h>
#include <stdlib.h>

int max[10][10], need[10][10], alloc[10][10], completed[10], safeSeq[10], available[10];

void display(int p, int r)
{
    int i, j;
    printf("\nMax matrix\t\tAllocation matrix\tRemaining matrix\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
            printf("%d ", max[i][j]);
        printf("\t\t");
        for (j = 0; j < r; j++)
            printf("%d ", alloc[i][j]);
        printf("\t\t");
        for (j = 0; j < r; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    printf("Available Resources: ");
    for (j = 0; j < r; j++)
        printf("%d ", available[j]);
    printf("\n");
}

int main()
{
    int flag = 0;
    int p, r;
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter MAX matrix: \n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Allocation matrix: \n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter the Available resources: ");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &available[j]);
    }

    for (i = 0; i < p; i++)
    {
        completed[i] = 0;
    }

    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;
    while (count < p)
    {
        int found = 0;
        for (i = 0; i < p; i++)
        {
            if (completed[i] == 0)
            {
                int j;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > available[j])
                        break;
                }
                if (j == r)
                {
                    int k;
                    for (k = 0; k < r; k++)
                        available[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    completed[i] = 1;
                    found = 1;
                    display(p, r);
                }
            }
        }
        if (found == 0)
            break;
    }

    if (count == p)
    {
        printf("System is in a safe state.\n");
        printf("Safe Sequence: ");
        for (i = 0; i < p; i++)
            printf("-> %d ", safeSeq[i]);
        printf("\n");
    }
    else
    {
        printf("System is not in a safe state.\n");
    }
    return 0;
}
