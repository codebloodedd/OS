// FCFS
#include <stdio.h>

float avgTAT = 0, avgWT = 0;
int n;

void sortArrival(int Time[n][6], int n)
{
    int i, j;
    int temp, temp1, temp2;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (Time[i][1] > Time[j][1])
            {
                temp1 = Time[i][1];
                Time[i][1] = Time[j][1];
                Time[j][1] = temp1;
                temp = Time[i][0];
                Time[i][0] = Time[j][0];
                Time[j][0] = temp;
                temp2 = Time[i][2];
                Time[i][2] = Time[j][2];
                Time[j][2] = temp2;
            }
        }
    }
}

void sortBurst(int Time[n][6], int n, int s, int currTime)
{
    int i, j;
    int temp, temp1, temp2;
    for (i = s; i < n; i++)
    {
        if (Time[i][1] <= currTime)
        {
            for (j = i; j < n; j++)
            {
                if (Time[i][2] > Time[j][2])
                {
                    temp1 = Time[i][1];
                    Time[i][1] = Time[j][1];
                    Time[j][1] = temp1;
                    temp = Time[i][0];
                    Time[i][0] = Time[j][0];
                    Time[j][0] = temp;
                    temp2 = Time[i][2];
                    Time[i][2] = Time[j][2];
                    Time[j][2] = temp2;
                }
            }
        }
    }
}

void fcfs(int Time[n][6], int n)
{
    int i, j;

    sortArrival(Time, n);

    Time[0][3] = Time[0][2] + Time[0][1];
    for (i = 1; i < n; i++)
    {
        if (Time[i][1] > Time[i - 1][3])
        {
            Time[i][3] = Time[i][1] + Time[i][2];
        }
        else
        {
            Time[i][3] = Time[i - 1][3] + Time[i][2];
        }
    }
    for (i = 0; i < n; i++)
    {
        Time[i][4] = Time[i][3] - Time[i][1];
        Time[i][5] = Time[i][4] - Time[i][2];
        avgTAT = avgTAT + Time[i][4];
        avgWT = avgWT + Time[i][5];
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT / n;
}

void sjfNP(int Time[n][6], int n)
{
    int i, j;
    int currTime = 0;
    sortArrival(Time, n);
    for (i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            Time[i][3] = Time[i][2] + Time[i][1];
        }
        else
        {
            Time[i][3] = Time[i - 1][3] + Time[i][2];
        }
        currTime = Time[i][3];
        sortBurst(Time, n, i + 1, currTime);
    }
    Time[n - 1][3] = Time[n - 2][3] + Time[n - 1][2];
    currTime = Time[n - 1][3];
    for (i = 0; i < n; i++)
    {
        Time[i][4] = Time[i][3] - Time[i][1];
        Time[i][5] = Time[i][4] - Time[i][2];
        avgTAT = avgTAT + Time[i][4];
        avgWT = avgWT + Time[i][5];
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT / n;
}

int main()
{
    int i, j, temp, temp1, temp2;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int Time[n][6];
    // 0 => ID
    // 1 => Arrival Time
    // 2 => Burst Time
    // 3 => Completion
    // 4 => Turn around Time
    // 5 => Waiting Time

    for (i = 0; i < n; i++)
    {
        Time[i][0] = i;
        printf("AT%d ", i);
        scanf("%d", &Time[i][1]);
        printf("BT%d ", i);
        scanf("%d", &Time[i][2]);
    }
    // fcfs(Time,n);
    sjfNP(Time, n);

    printf("Id AT BT CT TT WT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  %d  %d  %d  %d  %d\n", Time[i][0], Time[i][1], Time[i][2], Time[i][3], Time[i][4], Time[i][5]);
    }
    printf("Average Turnaround Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);
    return 0;
}
