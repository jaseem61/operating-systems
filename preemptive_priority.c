#include<stdio.h>
void main()
{
    int bt[10],at[10],p[10],wt[10],tat[10],avg_wt,avg_tat,n,i,j,c[10],count=0,total_tat=0,total_wt=0,pid[10],position,temp,time,smallest,t[i];
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the arrival time:");
    for(i=0;i<n;i++)
    {
    scanf("%d",&at[i]);
    pid[i]=i+1;
    }
    printf("Enter the burst time:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        t[i]=bt[i];
    }
    printf("Enter the priority:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        c[i]=0;
    }
    for(i=0;i<n;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[position])
            {
                position=j;
            }
        }
        temp=at[position];
        at[position]=at[i];
        at[i]=temp;
        temp=bt[position];
        bt[position]=bt[i];
        bt[i]=temp;
        temp=p[position];
        p[position]=p[i];
        p[i]=temp;
        temp=pid[position];
        pid[position]=pid[i];
        pid[i]=temp;
    }
    p[9]=999;
    time=0;
    printf("\nGhant chart is as shown:\n");
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
        if(at[i]<=time&&p[i]<p[smallest]&&bt[i]>0)
        {
            smallest=i;
        }
    	}
        printf("%d-->",pid[smallest]);
        bt[smallest]--;
        if(bt[smallest]==0)
        {
        count++;
        wt[smallest]=time+1-at[smallest]-t[smallest];
        tat[smallest]=time+1-at[smallest];
        }
    }
    for(i=0;i<n;i++)
    {
        total_wt=total_wt+wt[i];
        total_tat=total_tat+tat[i];
    }
    printf("\nprocess_id\t\tat\t\tbt\t\twt\t\ttat");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",pid[i],at[i],t[i],wt[i],tat[i]);
    }
    printf("\naverage waiting time is: %f",(float)total_wt/n);
    printf("\naverage turn around time is: %f",(float)total_tat/n);
}
