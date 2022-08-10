#include<iostream>
#include <stdio.h>

int current[5][5], maximum_claim[5][5], available[5];//declaring 2d array for current position of each process
int allocation[5] = {0, 0, 0, 0, 0};//initially set allocation of resources to each process to zero
int maxres[5], running[5], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;
//maxres takes total resources
//current postion means which process has taken which resources
//maximun claim == maximum no of process require to complete the process
int main()
{
    printf("\nEnter number of processes: ");
    scanf("%d", &processes);//taking the number of process

    for (i = 0; i < processes; i++)
    {
        running[i] = 1;//setting all process running state =1
        counter++;//updating  counter so that if any process get complete we could decrease.
    }

    printf("\nEnter number of resources: ");
    scanf("%d", &resources);//taking the number of resources

    printf("\nEnter maximum availability of Resources without allocated to any process: ");
    for (i = 0; i < resources; i++)
    {
        scanf("%d", &maxres[i]);//taking total availability of resources
    }

    printf("\nEnter Allocated Resource Table:\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            scanf("%d", &current[i][j]);//taking current position of the each process
        }
    }

    printf("\nEnter Maximum resources aquire by process during execution:\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            scanf("%d", &maximum_claim[i][j]);//taking maximum need of each process
        }
    }

    printf("\nThe maximun resouces for process: ");
    for (i = 0; i < resources; i++)
    {
        printf("\t%d", maxres[i]);//printing total resources
    }

    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            printf("\t%d", current[i][j]);//printing current resources of each process
        }
        printf("\n");
    }

    printf("\nThe Maximum resouces aquire by process during execution::\n");
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            printf("\t%d", maximum_claim[i][j]);//printing max needs of each process
        }
        printf("\n");
    }

    for (i = 0; i < processes; i++)//4
    {
        for (j = 0; j < resources; j++)//3
        {
            allocation[j] += current[i][j];//setting current state to allocated state
        }
    }

    printf("\nAllocated resources:");
    for (i = 0; i < resources; i++)
    {
        printf("\t%d", allocation[i]);//sum of all allocated resources
    }

    for (i = 0; i < resources; i++)
    {
        available[i] = maxres[i] - allocation[i];//finding available resources by substracting total-allocated
    }

    printf("\nAvailable resources:");
    for (i = 0; i < resources; i++)
    {
        printf("\t%d", available[i]);// printing total availability
    }
    printf("\n");

    while (counter != 0)//until all the process get completed
    {
        safe = 0;//safe 0 mean unsafe and safe 1 means safe
        for (i = 0; i < processes; i++)
        {
            if (running[i])//we has already set running state of each process to 1 so that we could easily get status of process
            {
                exec = 1;
                for (j = 0; j < resources; j++)
                {
                    if (maximum_claim[i][j] - current[i][j] > available[j])//if required resources is greater than available.
                    {
                        exec = 0;
                        break;
                    }
                }
                if (exec)//only for which process execute
                {
                    printf("\nProcess%d is executing\n", i + 1);
                    running[i] = 0;
                    counter--;//update the counter i.e. here one process is completed
                    safe = 1;//setting state of that process is 1

                    for (j = 0; j < resources; j++)
                    {
                        available[j] += current[i][j];//iupdating the available array by adding current state of that process in the available array.
                    }
                    break;
                }
            }
        }
        if (!safe)//not safe
        {
            printf("\nThe processes are in unsafe state.\n");
            break;
        }
        else
        {
            printf("\nThe process is in safe state");
            printf("\nAvailable vector:");//showing availability vector

            for (i = 0; i < resources; i++)
            {
                printf("\t%d", available[i]);//printing available array
            }

            printf("\n");
        }
    }
    return 0;
}