#include <stdio.h>

int main()
{
    int bsize[10], psize[10], bno, pno, flag[10], allocation[10], i, j;
    for (i = 0; i < 10; i++)
    {
        flag[i] = 0;
        allocation[i] = -1;
    }
    printf("Enter the no of blocks: ");
    scanf("%d", &bno);
    printf("Enter block sizes:\n");
    for (i = 0; i < bno; i++)
    {
        scanf("%d", &bsize[i]);
    }
    printf("Enter the no of processes: ");
    scanf("%d", &pno);
    printf("Enter process sizes:\n");
    for (i = 0; i < pno; i++)
    {
        scanf("%d", &psize[i]);
    }
    for (i = 0; i < pno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (flag[j] == 0 && bsize[j] >= psize[i])
            {
                flag[j] = 1;
                allocation[j] = i;
                break;
            }
        }
    }
    printf("\nBlock Size\tProcess Size\n");
    for (i = 0; i < bno; i++)
    {
        printf("%d\t", bsize[i]);
        if (flag[j] == 1)
        {
            printf("\t\t%d\n", psize[allocation[i]]);
        }
        else
        {
            printf("Not allocated\n");
        }
    }

    return 0;
}