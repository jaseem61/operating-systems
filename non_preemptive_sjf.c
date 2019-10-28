#include <stdio.h>
void main()
{
  int at[10],bt[10],time=0,wt[10],tat[10],i,j,small,n,pid[10],remain,total_tat,total_wt,temp,c[10];
  printf("Enter the number of processes:");
  scanf("%d",&n);
  remain=n;
  printf("\nEnter the arrival time for the processes:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
    pid[i]=i+1;
    c[i]=0;
  }
  printf("Enter the burst time for the processes:");
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
  printf("\n\nGHANT CHART\n\n");
  bt[9]=999;
while(remain!=0)
  {
    small=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time&&bt[i]<bt[small]&&c[i]==0)
      {
        small=i;
      }
    }
    if(small!=9 && c[small]==0)
    {
      printf("%d\t",time);
      time=time+bt[small];
      tat[small]=time-at[small];
      wt[small]=time-bt[small]-at[small];
      printf("P[%d]\t%d\t",pid[small],time);
      remain--;
      c[small]=1;
    }
    else
    {
    	time++;
	}
  }
  for(i=0;i<n;i++)
  {
    total_tat=total_tat+tat[i];
    total_wt=total_wt+wt[i];
  }
  printf("\nThe average waiting time is : %f",(float)total_wt/n);
  printf("\nThe average turn around time is : %f",(float)total_tat/n);
}
