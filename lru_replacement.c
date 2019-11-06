#include<stdio.h>
int find_lru(int time[],int n)
{
  int i,smallest=time[0],pos=0;
  for(i=1;i<n;i++)
  {
  if(time[i]<smallest)
  {
    smallest=time[i];
    pos=i;
  }
  }
  return pos;
}
void main()
{
	int np,nf,i,p[20],f[10],f1,f2,j,count=0,time[10],pos,fault=0;
  printf("\nEnter the no. of pages:\n");
  scanf("%d",&np);
  printf("\nEnter the pages:\n");
  for(i=0;i<np;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("\nEnter the no. of frames:\n");
  scanf("%d",&nf);
  printf("\n\nFRAME ALLOCATION\n\n");
  for(i=0;i<nf;i++)
  {
    f[i]=-1;
  }
  for(i=0;i<np;i++)
  {
    f1=f2=0;
    for(j=0;j<nf;j++)
    {
      if(f[j]==p[i])
      {
        count++;
        time[j]=count;
        f1=f2=1;
        break;
      }}
      if(f1==0)
      {
        for(j=0;j<nf;j++)
        {
        if(f[j]==-1)
        {
          f[j]=p[i];
          count++;
          time[j]=count;
          f2=1;
          fault++;
          break;
        }
      }
    }
      if(f2==0)
      {
        pos=find_lru(time,nf);
        f[pos]=p[i];
        count++;
        time[pos]=count;
        fault++;
        f2=1;
      }
      printf("\n");
      for(j=0;j<nf;j++)
      {
        printf("%d\t",f[j]);
      }
  }
  printf("\n\nTotal page fault is : %d",fault);
}
