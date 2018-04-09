#include<stdio.h>
 
void main()
{
    int BurstTime[20];
int p[20];
int WaitingTime[20];
int TurnAroundTime[20];
int TotalProcesses, i, j;
int total=0;
int pos,temp;
    float avg_WaitingTime,avg_TurnAroundTime;
    printf("Enter total number of process:");
    scanf("%d",& TotalProcesses);
 
    printf("\nEnter Burst Time for each process:\n");
    for(i=0;i<TotalProcesses;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&BurstTime[i]);
        p[i]=i+1;           
//code for process number
    }
 
    //sorting burst time in ascending order by sorting with selection sort
    for(i=0;i<TotalProcesses;i++)
    {
        pos=i;
        for(j=i+1;j<TotalProcesses;j++)
        {
            if(BurstTime[j]<BurstTime[pos])
                pos=j;
        }
 
        temp=BurstTime[i];
        BurstTime[i]=BurstTime[pos];
        BurstTime[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    WaitingTime[0]=0;            
//waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<TotalProcesses;i++)
    {
        WaitingTime[i]=0;
        for(j=0;j<i;j++)
            WaitingTime[i]+=BurstTime[j];
 
        total+=WaitingTime[i];
    }
 
    avg_WaitingTime=(float)total/TotalProcesses;      
//average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<TotalProcesses;i++)
    {
        TurnAroundTime[i]=BurstTime[i]+WaitingTime[i];     
//calculate turnaround time
        total+=TurnAroundTime[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],BurstTime[i],WaitingTime[i],TurnAroundTime[i]);
    }
 
    avg_TurnAroundTime=(float)total/TotalProcesses;     
//average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_WaitingTime);
    printf("\nAverage Turnaround Time=%f\n",avg_TurnAroundTime);
}
