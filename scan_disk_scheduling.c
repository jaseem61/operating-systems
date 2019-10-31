#include<stdio.h>
void main()
{
int n,i,h,temp,time,arr[10],st[10],c[10],m=0,total_st=0,count;
printf("=======SCAN DISK SCHEDULING=====");
printf("\n\nEnter the number of items in the cylinder:\n");
scanf("%d",&n);
count=n;
printf("\nEnter the items in the cylinder:\n");
for(i=0;i<n;i++)
{
  scanf("%d",&arr[i]);
  c[i]=0;
}
printf("\nenter the start position of the head:\n");
scanf("%d",&h);
temp=h;
time=h;
printf("\n");
while(time!=200&&count!=0)
{
  for(i=0;i<n;i++)
  {
    if(arr[i]==time&&c[i]==0)
    {
      count--;
      st[i]=time-h;
      c[i]=1;
      h=time;
      printf("%d-->",arr[i]);
    }
  }
  time++;
}
if(h!=199)
{
  m=199-h;
}
time--;
while(time>=0&&count!=0)
{
  for(i=0;i<n;i++)
  {
    if(arr[i]==time&&c[i]==0)
    {
      count--;
      st[i]=(h+m)-time;
      m=0;
      c[i]=1;
      h=time;
      printf("%d-->",arr[i]);
    }
  }
  time--;
}
printf("\n");
for(i=0;i<n;i++)
{
  total_st=total_st+st[i];
}
printf("\ntotal scan time is %d",total_st);
printf("\naverage scan time is %f",(float)total_st/n);
}
