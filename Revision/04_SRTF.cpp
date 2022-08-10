#include<iostream>

using namespace std;
int main()
{
    int a[10],b[10],x[10];// a is for arrival time and  b is for burst time and x is copy of burst time
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;//
    double avg=0,tt=0,end;//

    cout<<"\nEnter the number of Processes: ";  //taking number of process
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process: ";  //taking arrival time of each process
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter burst time of process: ";  //taking burst time of each process
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];//copying burst time into array x

// sjf logic
    b[9]=9999;//so that we could find shortest remaining time easily.
    for(time=0; count!=n; time++)//until number of process be 0.
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )//arrival time = 0 burst time (any value )
                smallest=i;//smallest = 0
        }
        b[smallest]--;//burst time decreased by single unit

        if(b[smallest]==0)
        {
            count++;// it means one process is completed
            end=time+1;//completed
            completion[smallest] = end;//here end is completion time of each process
            waiting[smallest] = end - a[smallest] - x[smallest];//completion time - AT -BT
            turnaround[smallest] = end - a[smallest];//completion time-BT
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
}
// time complexity is greater than O(n^2)