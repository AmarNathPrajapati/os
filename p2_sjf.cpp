#include<algorithm>
#include <stdio.h>
#include <conio.h>
#define max 50
using namespace std;
int main()
{
    int i, j, n, t, processNo[max], burst_time[max], waiting_time[max], tat[max];
    float awt = 0, atat = 0;//atat-->average turn around time
    printf("Enter the number of the process: ");
    scanf("%d", &n);
    printf("Enter the process number: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &processNo[i]);
    }
    printf("Enter the burst time of process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &burst_time[i]);
    }
    sort(burst_time,burst_time+n);//sorting burst time
    printf("process\t  burst time \t waiting time \t turn around time\n");
    for (i = 0; i < n; i++)
    {
        waiting_time[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            waiting_time[i] = waiting_time[i] + burst_time[j];
        }
        tat[i] = waiting_time[i] + burst_time[i];
        awt = awt + waiting_time[i];
        atat = atat + tat[i];
        printf("%d\t\t %d\t\t %d\t\t %d\n", processNo[i], burst_time[i], waiting_time[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time =%f\n", awt);
    printf("Average turn around time=%f", atat);
    getch();
}