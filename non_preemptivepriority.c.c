#include<stdio.h>
void main()
{
	int n,count,i,at[10],bt[10],p[10],pid[10],c[10],smallest,time=0,wt[10],tat[10],total_wt=0,total_tat=0;
	printf("\n\nnon_preemptive priority\n\n");
  printf("Enter the number of procesess:\n");
  scanf("%d",&n);
  count=n;
  printf("\nEnter the arrival time of the procesess:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&at[i]);
    c[i]=0;
    pid[i]=i+1;
  }
  printf("\nEnter the burst time of the processes:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
  }
  printf("\nEnter the priority of the processes:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  p[9]=999;
  printf("\n\nGHANTT CHART\n\n");
  while(count!=0)
  { smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time&&p[i]<p[smallest]&&c[i]==0)
      {
        smallest=i;
      }
    }
    if(smallest!=9)
    {
      time=time+bt[smallest];
      wt[smallest]=time-bt[smallest]-at[smallest];
      tat[smallest]=time-at[smallest];
      c[smallest]=1;
      printf("%d---->",pid[smallest]);
      count--;
    }
    else
    {
    	time++;
	}
  }
  	printf("\nprocess_id\t\tat\t\tbt\t\twt\t\ttat");
  for(i=0;i<n;i++)
  {
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",pid[i],at[i],bt[i],wt[i],tat[i]);
    total_wt=total_wt+wt[i];
    total_tat=total_tat+tat[i];
  }
  printf("\nThe average waiting time is %f",(float)total_wt/n);
  printf("\nThe average turn around time is %f",(float)total_tat/n);
}
