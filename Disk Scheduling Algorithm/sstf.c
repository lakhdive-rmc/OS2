//SSTF selects the request closest to the current head position. It reduces seek time but may cause starvation of far requests.
#include<stdio.h>
#include<stdlib.h>
main()
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
	printf("\nSeek Sequence : %d",head);
	for(i=0;i<n;i++)
	{
		min = 1000;
		for(j=0;j<n;j++)
		{
			if ( (abs(head - req[j]))< min)
			{
				min = abs(head-req[j]);
				index = j;
			}
		}
		total = total + abs(head-req[index]);
		head = req[index];
		req[index] = 1000;
		printf("-> %d",head);
	}
	printf("\nTotal Head Movement=%d",total);
}
