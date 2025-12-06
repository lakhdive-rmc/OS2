//Also callled as Elevator Algorithm, Disk arm moves in one direction, servicing requests until it reaches the end, then reverses.
//It provides better performance by reducing overall seek time.
#include<stdio.h>
#include<stdlib.h>
void sort(int req[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
}
void scan(int req[], int n, int head,int maxc)
{
	int i, hm,index,total=0;
	printf("Direction: Right\n");
        // Find the index of the first request greater than the current head position
        for (i = 0; i < n; ++i) {
            if (req[i] > head) {
                index = i;
                break;
            }
        }
        // Serve requests from the beginning of the disk to the end
        for (i = index; i < n; i++) {
            hm = abs(req[i] - head);
            printf("Request %d served. Head movement: %d\n", req[i], hm,total);
            total = total + hm;
            head = req[i];
        }
	hm = abs(maxc - head -1);
	total = total + hm;
	head=maxc-1;
	printf("Reached to Right End, Head Movement : %d\n",hm);
// Serve requests in reverse order until the beginning of the disk
        for (i = index - 1; i >= 0; i--) {
	    hm = abs(req[i] - head);
            printf("Request %d served. Head movement: %d\n", req[i], hm);
            total = total + hm;
            head = req[i];

        }
	printf("\nTotal Head Movement=%d",total);
}
void main()
{
	int req[20],i,n,head,maxc;
	printf("Enter the no.of processes to be requested : ");
	scanf("%d",&n);
	printf("Enter the request : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	// Sort the Requests in ascending order
	sort(req,n);
	printf("\nSorted Request : ");
	for(i=0; i<n;i++)
		printf("\t%d",req[i]);
	printf("\nEnter the initial head position : ");
	scanf("%d",&head);
	printf("\nEnter Number of Cylinder : ");
	scanf("%d",&maxc);
	printf("\nSeek Sequence : %d",head);

	scan(req,n,head,maxc);
}
