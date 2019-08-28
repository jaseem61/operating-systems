#include <stdio.h>
#include <stdlib.h>
int mutex=1,full=0,empty=3,x=0;
void main()
{
int c;
int wait(int);
int signal(int);
void producer();
void consumer();
while(1)
{
printf("\nEnter the choice:\n1.produce\t2.consume\t3.exit\n");
scanf("%d",&c);
switch(c)
{
case 1:if((mutex==1)&&(empty!=0))
	producer();
else
printf("\nbuffer is full!");
break;
case 2: if((mutex==1)&&(full!=0))
    consumer();
else
    printf("\nbuffer is empty!");
    break;

case 3:
    exit(0);
    break;
}
}
}
int wait(int a)
{
    return(--a);
}
int signal(int a)
{
    return(++a);
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
x++;
empty=wait(empty);
printf("\nitem %d is produced",x);
mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    empty=signal(empty);
    full=wait(full);
    printf("\nitem %d is consumed",x);
    x--;
    mutex=signal(mutex);
}