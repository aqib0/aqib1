#include<stdio.h>
void main()
 {
   int temp,n,process[10],priority[10],pt[10],wait[10],time[10],average_wait,average_turnaround,i,j;
   printf("total no. of process : ");
   scanf("%d",&n);
   printf("\n Enter process : time priorities \n");
   for(i=0;i<n;i++)
    {
      printf("\nProcess no %d : ",i+1);
      scanf("%d  %d",&pt[i],&priority[i]);
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
         temp=pt[i];
         pt[i]=pt[j];
         pt[j]=temp;
         temp=process[i];
         process[i]=process[j];
         process[j]=temp;
      }
   }
}
wait[0]=0;
average_wait=0;
time[0]=pt[0];
average_turnaround=time[0];
for(i=1;i<n;i++)
 {
   wait[i]=time[i-1];
   average_wait+=wait[i];
   time[i]=wait[i]+pt[i];
   average_turnaround+=time[i];
 }
printf("\n\n Job \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(i=0;i<n;i++)
  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",process[i],pt[i],wait[i],time[i],priority[i]);
average_wait=average_wait/n;
average_turnaround=average_turnaround/n;
printf("\n Average Wait Time : %d \n",average_wait);
printf("\n Average Turn Around Time : %d \n",average_turnaround);
getch();
}
