//FCFS processes disk requests in the order they arrive. Simple and fair but may lead to long seek times.
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int req[20],temp,i,j,n,head,total=0,index,min;
	printf("Enter the no.of processes to be requested : ");
	scanf("%d",&n);
	printf("Enter the request : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	printf("Enter the initial head position : ");
	scanf("%d",&head);
	printf("\nSeek Sequence  = %d ",head);
	for(i=0;i<n;i++)
	{
		total = total + abs(head-req[i]);
		head = req[i];
		printf("\t->%d",head);
	}
	printf("\nTotal Head Movement=%d",total);
}
