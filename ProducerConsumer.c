// Producer-Consumer
#include <stdio.h>
#include <stdlib.h>
int full = 0, empty = 3, mutex = 1;

int wait(int s)
{
    s--;
    return s;
}

int signal(int s)
{
    s++;
    return s;
}

void produce()
{
    int i;
    int x = 0;
    wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("Produced\nFull: %d\tEmpty: %d\n", full, empty);
    signal(mutex);
    printf("Do you want to produce more?\n1.Yes\n2.No\n");
    scanf("%d", &i);
    if (i == 1)
    {
        if (mutex == 1 && empty != 0)
        {
            produce();
        }
        else
        {
            printf("Buffer is full\n\n");
        }
    }
    else
    {
        return;
    }
}

void consume()
{
    int i;
    wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumed\nFull: %d\tEmpty: %d\n", full, empty);
    signal(mutex);
    printf("Do you want to consume more?\n1.Yes\n2.No\n");
    scanf("%d", &i);
    if (i == 1)
    {
        if (mutex == 1 && full != 0)
        {
            consume();
        }
        else
        {
            printf("Buffer is empty\n\n");
        }
    }
    else
    {
        return;
    }
}

int main()
{
    int n = 0;
    while (n != 3)
    {
        printf("1.Producer\n2.Comsumer\n3.Exit\nEnter the choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                produce();
            }
            else
            {
                printf("Buffer is full");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consume();
            }
            else
            {
                printf("Buffer is empty");
            }
            break;
        case 3:
            break;
        }
    }
    return 0;
}