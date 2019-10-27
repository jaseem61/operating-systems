#include<stdio.h>
void main()
{
int at[10],bt[10],pid[10],i,n,temp,small,time=0,c[10],wt[10],tat[10],total_wt,total_tat,j;
printf("Enter the number of processes:");
scanf("%d",&n);
printf("\nEnter the arrival time of the processes:");
for(i=0;i<n;i++)
{
scanf("%d",&at[i]);
pid[i]=i+1;
c[i]=0;
}
printf("\nEnter the burst time of the processes:");
for(i=0;i<n;i++)
{
  scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(at[j]<at[i])
		{
			temp=at[i];
			at[i]=at[j];
			at[j]=temp;
			temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;
			temp=pid[i];
			pid[i]=pid[j];
			pid[j]=temp;
		}
	}
}
printf("\nGHANT CHART\n");
for(j=0;j<n;j++)
{
for(i=0;i<n;i++)
{
if(at[i]<=time&&c[i]==0)
{
  printf("%d",time);
  time=time+bt[i];
  wt[i]=time-at[i]-bt[i];
  tat[i]=time-at[i];
  c[i]=1;
  printf("\tP[%d]\t%d\t",pid[i],time);
}
}
}
printf("\nThe waiting time & turn around time is:");
for(i=0;i<n;i++)
{
  printf("\nWT[%d] = %d",pid[i],wt[i]);
  printf("\nTAT[%d] = %d",pid[i],tat[i]);
  total_wt=total_wt+wt[i];
  total_tat=total_tat+tat[i];
}
printf("\nThe average waiting time is %f",(float)total_wt/n);
printf("\nThe average turn around time is %f",(float)total_tat/n);
}
