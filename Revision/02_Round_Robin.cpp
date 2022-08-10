#include <stdio.h>
#include <conio.h>// it stands for console input and output

int main()
{
    int i, no_of_process, sum = 0, count = 0, y, qt, wt = 0, tat = 0, at[10], bt[10], temp[10];
    //sum is the instant of completion time
    //qt -- quantum time
    float avg_wt, avg_tat;
    printf(" Total number of process in the system: ");
    scanf("%d", &no_of_process);
    y = no_of_process; // Assign the number of process to variable y so that we can store the status of process i.e. if process is get completed then we wiil reduce the value of the number of process.

    // Use for loop to enter the details of the process like Arrival time and the Burst Time
    for (i = 0; i < no_of_process; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" Arrival time is:  "); // Accepting arrival time
        scanf("%d", &at[i]);
        printf(" Burst time is:  "); // Accepting the Burst time
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // store the burst time in temp array because may be bt left after time quantaum
    }
    // Accept the Time qunat
    printf("Enter the Time Quantum time for the process:  ");
    scanf("%d", &qt);
    // Displaying the process No, burst time, Turn Around Time and the waiting time
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    //Round Robin logic
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= qt && temp[i] > 0) // define the conditions
        {
            sum = sum + temp[i];//update completion time
            temp[i] = 0;
            count = 1;// one process is completed
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - qt; // burst time - quantum time
            sum = sum + qt; //sum is here completion time
        }
        if (temp[i] == 0 && count == 1)//process get completed
        {
            y--; // decrement the process no.
            printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);           //tat = completion time - arrival time;
                        //waiting time = completion time -arrival time - burst time = tat-burst time
            wt = wt + sum - at[i] - bt[i];// wt + new Wt
            tat = tat + sum - at[i];// tat + new Tat
            count = 0;
        }
        if (i == no_of_process - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)//here sum is completion time
        {
            i++;//if any process is left
        }
        else
        {
            i = 0;
        }
    }
    // represents the average waiting time and Turn Around time
    avg_wt = wt * 1.0 / no_of_process;
    avg_tat = tat * 1.0 / no_of_process;
    printf("\n Average waiting Time: \t%f", avg_wt);
    printf("\n Average Turn Around Time: \t%f", avg_tat);
    getch();
}
//time complexity O(n)