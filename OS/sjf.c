#include<stdio.h>
int main()
{
	int p[20],bt[20],wt[20],tat[20],i,j,n,pos,temp,total=0;
	float avg_wt,avg_tat;
	printf("enter the number of processes\n");
	scanf("%d",&n);
	printf("enter the burst time\n");
	for(i=0;i<n;i++)
	{
		printf("p[%d]:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
		total+=wt[i];
	}
	avg_wt=(float)total/n;
	total=0;
	printf("\nProcess\tBurst time\twaiting time\tturnaround time");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\np%d\t\t%d\t\t%d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=(float)total/n;
	printf("\n\n Average waiting time : %f",avg_wt);
	printf("\n Average turnaround time :%f",avg_tat);
	return 0;
}
