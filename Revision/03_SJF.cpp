#include <stdio.h>
#include <conio.h> // it stands for console input and output
#define max 30
int main()
{
    int i, j, n, t, p[max], bt[max], wt[max], tat[max];//p is process number
    // n -- number of process 
    float awt = 0, atat = 0;
    printf("Enter the number of the process: ");
    scanf("%d", &n);
    printf("Enter the process number: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the burst time of process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    // applying bubble sort technique to sort according to their burst time
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])//sorting in ascending order
            {
                t = bt[j];
                bt[j] = bt[j + 1];      // these three steps are for swaping of burst time
                bt[j + 1] = t;
                t = p[j];
                p[j] = p[j + 1];        // to arrange process in same order, here swapping is also done.
                p[j + 1] = t;
            }
        }
    }
    // SJF logic 
    printf("process \t burst time \t waiting time \t turn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;//so that it doesn't store garbage value
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {   
            wt[i] = wt[i] + bt[j];// getting waiting time by adding burst time of all process before i.
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time =%f\n", awt);
    printf("Average turn around time=%f", atat);
    getch();// it hold the output screen for some time until the user passes a key from keyboard.
}