#include<stdio.h>
void main()
{
	int nf,np,i,j,p[20],f[10],k,f1,f2,fault=0;
  printf("\nEnter the number of frames:\n");
  scanf("%d",&nf);
  printf("\nEnter the number of pages:\n");
  scanf("%d",&np);
  printf("\nEnter the reference string:\n");
  for(i=0;i<np;i++)
  {
    scanf("%d",&p[i]);
  }
  for(i=0;i<nf;i++)
  {
    f[i]=-1;
  }
  k=0;
  for(i=0;i<np;i++)
  {
  	f1=f2=0;
    for(j=0;j<nf;j++)
    {
      if(f[j]==p[i])
      {
        f1=f2=1;
        break;
      }
    }
    if(f1==0)
    {
    for(j=0;j<nf;j++)
    {
      if(f[j]==-1)
      {
        f[j]=p[i];
        fault++;
        f2=1;
        break;
      }
    }
  }
  if(f2==0)
      {
        f[k]=p[i];
        k=(k+1)%nf;
        fault++;
      }
      printf("\n");
      for(j=0;j<nf;j++)
      {
      	printf("%d\t",f[j]);
	  }
    }
    printf("\n\nTotal page fault is: %d",fault);
  }
