#include<stdio.h>
void main()
{ int i,n,arr[10],st[10],time,total_st=0,h;
  printf("======FCFS DISK SCHEDULING======");
  printf("\n\nEnter the number of items in the pipe:\n");
  scanf("%d",&n);
  printf("\nEnter the items in the pipe:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("\nEnter the position of the read head:\n");
  scanf("%d",&h);
  time=h;
  printf("\n\n");
  for(i=0;i<n;i++)
  {
  while(time!=arr[i])
  {
    if(time<arr[i])
    {
      time++;
    }
    else if(time>arr[i])
    {
      time--;
    }
  }
  if(time>h)
  {
    st[i]=time-h;
  }
  else if(time<h)
  {
    st[i]=h-time;
  }
  h=time;
  printf("%d-->",arr[i]);
  total_st=total_st+st[i];
}
printf("\n\nThe total scan time is %d",total_st);
printf("\nThe average scan time is %f",(float)total_st/n);
}
