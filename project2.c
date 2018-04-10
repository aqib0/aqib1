#include<stdio.h>
#include<stdlib.h>
 main()
{
    int BurstTime[20] , p[20], Waiting[20], TurnAround[20], TotalProcesses, i, j, total=0, position,temp;
    float avg_Waiting,avg_TurnAround;
    printf("Enter total number of process:");
    scanf("%d",& TotalProcesses);
    printf("\nEnter Burst Time for each process:\n");
    for(i=0;i<TotalProcesses;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&BurstTime[i]);
        p[i]=i+1;           
    }
    for(i=0;i<TotalProcesses;i++)
    {
        position=i;
        for(j=i+1;j<TotalProcesses;j++)
        {
            if(BurstTime[j]<BurstTime[position])
                position=j;
        }
 
        temp=BurstTime[i];
        BurstTime[i]=BurstTime[position];
        BurstTime[position]=temp;
        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }
    Waiting[0]=0;          
    for(i=1;i<TotalProcesses;i++)
    {
        Waiting[i]=0;
        for(j=0;j<i;j++)
        Waiting[i]+=BurstTime[j];
        total+=Waiting[i];
    }
 
    avg_Waiting=(float)total/TotalProcesses;      
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<TotalProcesses;i++)
    {
        TurnAround[i]=BurstTime[i]+Waiting[i];     
        total+=TurnAround[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],BurstTime[i],Waiting[i],TurnAround[i]);
    }
    avg_TurnAround=(float)total/TotalProcesses;     
    printf("\n\nAverage Waiting Time=%f",avg_Waiting);
    printf("\nAverage Turnaround Time=%f\n",avg_TurnAround);
}
