#include<iostream>
using namespace std;
#define max 50
int main(){
    int n,burst_time[max],waiting_time[max],TA_time[max];//TA->Turn Around
    float AW_time=0,ATA_time=0;//AW->average waiting ,ATA->average turn around
    cout<<"Enter the number of the process(s): ";
    cin>>n;//taking No. of process from user
    cout<<"Enter the burst time for the process(s): ";
    for (int i = 0; i < n; i++)
    {
        cin>>burst_time[i];// set the burst_time of the process
    }
    cout<<"process\t  burst_time\t waiting_time\t turn around time"<<endl;
    for (int i = 0; i < n; i++)
    {
        waiting_time[i]=0;// initially waiting time of all process is zero;
        TA_time[i]=0;// initially turn around time of all process is zero;
        for (int j = 0; j < i; j++)
        {
            // getting waiting_time of the process 'i' by adding burst_time of all process before process 'i';
            waiting_time[i] = waiting_time[i] + burst_time[j]; 
        }
        TA_time[i] =waiting_time[i] + burst_time[i];
        AW_time = AW_time + waiting_time[i];
        ATA_time = ATA_time + TA_time[i];
        cout<<i+1<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<TA_time[i]<<endl;
    }
    AW_time = AW_time/n;
    ATA_time = ATA_time/n;
    cout<<"Average waiting time : "<<AW_time<<endl;
    cout<<"Average Turn Around time : "<<ATA_time<<endl;
return 0;
}