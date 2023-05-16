// FIFO PAGE SCHEDULING
#include <stdio.h>
#include <string.h>

int main()
{
    int page[100];
    int frames[100];
    int i, j, k, hit = 0, fault = 0;
    int p, f, c = 0, x = 0;
    double hr, fr;
    char ch;
    printf("Enter no of pages: ");
    scanf("%d", &p);
    printf("\nEnter no of frames: ");
    scanf("%d", &f);
    printf("\nEnter page sequence: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &page[i]);
    }
    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
    }
    for (i = 0; i < p; i++)
    {
        k = 0;
        for (j = 0; j < f; j++)
        {
            if (page[i] == frames[j])
            {
                k = 1;
                break;
            }
        }
        if (k == 1)
        {
            ch = "H";
            hit++;
        }
        else
        {
            ch = "F";
            fault++;
            if (c < f)
            {
                frames[c] = page[i];
                c++;
            }
            else
            {
                frames[x] = page[i];
                if (x = f - 1)
                {
                    x = 0;
                }
                else
                {
                    x++;
                }
            }
        }
        for (j = 0; j < f; j++)
        {
            printf("%d\t", frames[j]);
        }
        printf("%c\n", ch);
    }
    hr = (double)hit / p;
    fr = (double)fault / p;
    printf("No of Hits: %d\n", hit);
    printf("No of faults: %d\n", fault);
    printf("Hit ratio: %f\n", hr);
    printf("Fault ratio: %f\n", fr);
    return 0;
}