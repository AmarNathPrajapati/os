#include <bits/stdc++.h>

using namespace std;

struct process
{
	int processno;
	int AT;
	int BT;

	// for backup purpose to print in last
	int BTbackup;
	int WT;
	int TAT;
	int CT;
};

// creating a structure of 4 processes
struct process p[4];

// variable to find the total time
int totaltime = 0;
int prefinaltotal = 0;


bool compare(process p1, process p2)
{
	// compare the Arrival time of two processes
	return p1.AT < p2.AT;
}

// finding the largest burst Time among all the available
// process at that time
int findlargest(int at)
{
	int max = 0, i;
	for (i = 0; i < 4; i++)
	{
		if (p[i].AT <= at) // process can come or not
		{
			if (p[i].BT > p[max].BT)//and bursttime is high
				max = i;
		}
	}

	// returning the index of the process having the largest BT
	return max;
}

// function to find the completion time of each process
int findCT()
{

	int index;
	int flag = 0;
	int i = p[0].AT;// is process's arrival time
	while (1)
	{
		if (i <= 4)
		{
			index = findlargest(i);//to check process has largest burst time or not
		}

		else
			index = findlargest(4);
		cout << "Process executing at time " << totaltime
			 << " is: P" << index + 1 << "\t";

		p[index].BT -= 1;// main logic of pre-emptive algo
		totaltime += 1;//total time has increased
		i++;

		if (p[index].BT == 0)// if process is completed
		{
			p[index].CT = totaltime;
			cout << " Process P" << p[index].processno
				 << " is completed at " << totaltime;
		}
		cout << endl;

		// loop termination condition
		if (totaltime == prefinaltotal)
			break;
	}
}

int main()
{

	int i;

	for (i = 0; i < 4; i++)
	{
		p[i].processno = i + 1;
	}

	for (i = 0; i < 4; i++) // taking AT
	{
		p[i].AT = i + 1;
	}

	for (i = 0; i < 4; i++)
	{

		// assigning {2, 4, 6, 8} as Burst Time to the processes
		// backup for displaying the output in last
		// calculating total required time for terminating
		// the function().
		p[i].BT = 3 * (i + 1);
		p[i].BTbackup = p[i].BT;
		prefinaltotal += p[i].BT;//total burst time
	}

	cout << "PNo\tAT\tBT\n";

	for (i = 0; i < 4; i++)// showing output
	{
		cout << p[i].processno << "\t";
		cout << p[i].AT << "\t";
		cout << p[i].BT << "\t";
		cout << endl;
	}
	cout << endl;

	sort(p, p + 4, compare);//using in-built sort algorithm which takes two pointer and a fuction

	totaltime += p[0].AT;

	prefinaltotal += p[0].AT;
	findCT();
	int totalWT = 0;
	int totalTAT = 0;
	for (i = 0; i < 4; i++)
	{

		p[i].TAT = p[i].CT - p[i].AT;//calculating turn around time 
		p[i].WT = p[i].TAT - p[i].BTbackup;//tat-bursttime

		totalWT += p[i].WT;

		totalTAT += p[i].TAT;
	}

	cout << "After execution of all processes ... \n";

	cout << "PNo\tAT\tBT\tCT\tTAT\tWT\n";
	for (i = 0; i < 4; i++)
	{
		cout << p[i].processno << "\t";
		cout << p[i].AT << "\t";
		cout << p[i].BTbackup << "\t";
		cout << p[i].CT << "\t";
		cout << p[i].TAT << "\t";
		cout << p[i].WT << "\t";
		cout << endl;
	}

	cout << endl;
	cout << "Total TAT = " << totalTAT << endl;
	cout << "Average TAT = " << totalTAT / 4.0 << endl;
	cout << "Total WT = " << totalWT << endl;
	cout << "Average WT = " << totalWT / 4.0 << endl;
	return 0;
}
