/**
 * Implemention of priority scheduling algorithm
 * tat--turn around time
 * bt -- burst time
 * wt -- waiting time
 * at -- arrival time
 * pr -- priority
 * awt -- average waiting time
 * atat -- average turn around time
 */
#include<iostream>
#include<conio.h>
#define max 30 // it replace max variable by value 30.
using namespace std;

int main(){
    int i,n,j,t,k = 1,b = 0,min,temp[max],bt[max],at[max],wt[max],pr[max],tat[max];
    float awt = 0, atat = 0;
    //n is number of process
    //t 
    //b 
    cout<<"Enter the number of the process "<<endl;
    cin>>n;
    cout<<"Enter the burst time,arrival time and the priority of the process "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>bt[i]>>at[i]>>pr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(at[i]<at[j]){//sorting in ascending order using bubble sort
                t = at[j];
                at[j] = at[i];// swapping with a temporary variable t.
                at[i] = t;
                t = bt[j];
                bt[j] = bt[i];// swapping with a temporary variable t.
                bt[i] = t;
            }
        }
        
    }
    for (int j = 0; i < n; j++)
    {
        b = b + bt[j];
        min = bt[k];//executing first process
        for (int i = k; i < n; i++)
        {
            min = pr[k];//
            if(b>=at[i]){
                if(pr[i]<min){//min number means high priority
                    t = at[k];
                    at[k] = at[i];
                    at[i] = t;
                    t = bt[k];
                    bt[k] = bt[i];
                    bt[i] = t;
                    t= pr[k];
                    pr[k] = pr[i];
                    pr[i] = t;
                }
            }
        }
        k++;
    }
  
    temp[0] = 0;
    cout<<"process\t burst time\t arrival time\t priority\t waiting time\t turn around time\n";
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] -at[i];
        tat[i] = wt[i] +bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],pr[i],wt[i],tat[i]);
    } 
    awt = awt/n;
    atat = atat/n;
    cout<<"Average waiting time = " <<awt<<endl;
    cout<<"Average turn Around time = "<<atat<<endl;

return 0;
}
//time complexity greater than O(n^2)