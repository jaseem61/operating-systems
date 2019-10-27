#include<stdio.h>
void main()
{
  int time,count,at[10],bt[10],ts,pid[10],n,rt[10],remain,flag,i;
  printf("\nEnter the number of processes:");
  scanf("%d",&n);
  remain=n;
  printf("\nEnter the arrival time for each processes");
  for(i=0;i<n;i++)
  {
  scanf("%d",&at[i]);
  }
  printf("\nEnter the burst time for each processes");
  for(i=0;i<n;i++)
  {
  scanf("%d",&bt[i]);
  rt[i]=bt[i];
  }
  printf("\nEnter the time slice:");
  scanf("%d",&ts);
  printf("\npid\t\tTAT\t\tWT");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=ts&&rt[count]>0)
    {
      time=time+rt[count];
    	rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]=rt[count]-ts;
      time=time+ts;
    }
    if(rt[count]==0&&flag==1)
    {
      remain--;
      printf("\np[%d]\t\t%d\t\t%d",count+1,time-at[count],time-at[count]-bt[count]);
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
}

