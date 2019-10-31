#include<stdio.h>
void main()
{
int n,i,c[10],arr[10],small,h,time,count,st[10],st_total=0;
printf("======SSTF DISK SCHEDULING======");
printf("\n\nEnter the number of items in the pipe:\n");
scanf("%d",&n);
printf("\nEnter the items in the pipe:\n");
for(i=0;i<n;i++)
{
  scanf("%d",&arr[i]);
  c[i]=0;
}
printf("\nEnter the head position:\n");
scanf("%d",&h);
count=n;
time=h;
arr[9]=999;
while(count!=0)
{
  small=9;
  for(i=0;i<n;i++)
  {
    if(arr[i]<arr[small]&&c[i]==0)
    {
      small=i;
    }
  }
  time=arr[small];
  c[small]=1;
  st[small]=time-h;
  h=time;
  st_total=st_total+st[small];
  printf("%d-->",arr[small]);
  count--;
}
printf("\n\nThe total scan time is %d",st_total);
printf("\n\nThe average scan time is %f",(float)st_total/n);
}
