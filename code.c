#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>    
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int n,b[5],w[5],turn[5],avgw=0,avgturn=0,i,j;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	printf("Enter burst time for processes\n");
	for(i=0;i<n;i++)
	{
		printf("Burst time for process p[%d]:\n",i+1);
		scanf("%d",&b[i]);
	}	
	w[0]=0;
	for(i=1;i<n;i++)
	{
		w[i]=0;
		for(j=0;j<i;j++)
			w[i]+=b[j];
	}
	printf("\n Process burst time\tWaiting time\tTurn around time");
	for(i=0;i<n;i++)
	{
		turn[i]=b[i]+w[i];
		avgw+=w[i];
		avgturn+=turn[i];
		printf("\n p[%d]\t\t%d\t\t%d\t\t%d", i+1,b[i],w[i],turn[i]);
	}
	avgw=avgw/i;
	avgturn=avgturn/i;
	printf("\n Average waiting time:%d",avgw);
	printf("\n Average turn around time:%d",avgturn);
	return 0;
}
		
