#include<stdio.h>
#include<stdlib.h>
 void project()
 {
   int temp,n,process[10],priority[10],bt[10],wait[10],time[10],i,j;
   float average_wait,average_turnaround;
   printf("total no. of process : ");
   scanf("%d",&n);
   printf("\n Enter process :- Burst time :: priorities \n");
   for(i=0;i<n;i++)
    {
      printf("\nProcess no %d : ",i+1);
      scanf("%d %d",&bt[i],&priority[i]);
      process[i]=i+1;
    }
  for(i=0;i<n-1;i++)
   {
     for( j=i+1;j<n;j++)
     {
       if(priority[i]<priority[j])
       {
         temp=priority[i];
         priority[i]=priority[j];
         priority[j]=temp;
         temp=bt[i];
         bt[i]=bt[j];
         bt[j]=temp;
         temp=process[i];
         process[i]=process[j];
         process[j]=temp;
      }
   }
}
wait[0]=0;
average_wait=0;
time[0]=bt[0];
average_turnaround=time[0];
for(i=1;i<n;i++)
 {
   wait[i]=time[i-1];
   average_wait+=wait[i];
   time[i]=wait[i]+bt[i];
   average_turnaround+=time[i];
 }
printf("\n\n Job \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(i=0;i<n;i++)
{

  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",process[i],bt[i],wait[i],time[i],priority[i]);
}
average_wait=average_wait/n;
average_turnaround=average_turnaround/n;
printf("\n Average Wait Time : %f \n",average_wait);
printf("\n Average Turn Around Time : %f \n",average_turnaround);
}
main()
{
		int x,X;
	X:
	printf("enter 1 if you want to calculate and 0 if you dont want to calculate");
	scanf("%d",&x);
	while(x==1)
	{
	
	if(x==1)
	{
		project();
		goto X;
	}
	else
	 return(0);
}
}

