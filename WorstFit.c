// Worst fit
#include <stdio.h>

int main()
{
    int bsize[10], psize[10], bno, pno, allocation[10], i, j;
    for (i = 0; i < 10; i++)
    {
        // flag[i] = 0;
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
        int index = -1;
        for (j = 0; j < bno; j++)
        {
            if (bsize[j] >= psize[i])
            {
                if (index == -1)
                {
                    index = j;
                }
                else if (bsize[index] < bsize[j])
                {
                    index = j;
                }
            }
        }
        if (index != -1)
        {
            // flag[index] = 1;
            allocation[index] = i;
            bsize[index] = bsize[index] - psize[i];
        }
    }

    printf("\nBlock Size\tProcess Size\n");
    for (i = 0; i < bno; i++)
    {
        printf("%d\t", bsize[i]);
        // if(allocation[i]!=-1){
        printf("\t\t%d\n", psize[allocation[i]]);
        // }
        // else{
        //     printf("\t\tNot allocated\n");
        // }
    }

    return 0;
}