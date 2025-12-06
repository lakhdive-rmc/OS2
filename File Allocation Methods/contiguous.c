//It stores all file blocks in consecutive disk locations. Offers fast access but suffers from external fragmentation and difficulty in file growth.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct dirfile
{char fname[20];
	int startblk,length;
}direntry[20];

int bv[64];
int used=0;
int totalfile=0;
int n;

void initialize()
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++){
		if(rand()%2==0){
			bv[i]=0;
			used++;
		}else{
			bv[i]=1;
		}
	}
}

void showbv(){
	int i;
	printf("block number\t status\n");
	for(i=0;i<n;i++){
		printf("%d\t\t",i);
		if(bv[i]==0){
			printf("allocated\n");
		}else{
			printf("Free\n");
		}
	}
}

int search(int length)
{
	int i,j,flag=1,blknum;
	for(i=0;i<n;i++)
	{
		if(bv[i]==1)
		{
		flag=1;
		for(blknum=i,j=0;j<length;j++)
		{
			if(bv[blknum]==1)
			{
				blknum++;
				continue;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			return i;
		}
	}
	return -1;
}

void createfile()
{
	char fname[10];
	int length,blknum,k;
	printf("\nEnter File Name : ");
	scanf("%s",&fname);
	printf("enter the length of file:");
	scanf("%d",&length);

	if(length<=n-used)
	{
		blknum=search(length);
	}
	else{
		blknum=-1;
	}
	if(blknum==-1)
	{
		printf("error: no disk space available\n");
	}
	else
	{
		printf("\n block allocated\n");
		used=used+length;
		for(k=blknum; k<(blknum+length);k++)
			{	bv[k] = 0;
			}
		k=totalfile++;
		strcpy(direntry[k].fname,fname);
		direntry[k].startblk=blknum;
		direntry[k].length=length;
	}
}



void displaydir()
{
	int k;
	printf("\t filename\t start\tsize\n");
	for(k=0;k<totalfile;k++)
	{
		printf("%s\t%d\t%d\n",direntry[k].fname,direntry[k].startblk,direntry[k].length);
	}
	printf("\n used block=%d",used);
	printf("\n free block =%d\n",n-used);
}

int main()
{
	int choice;
		printf("enter the number of blocks in the disk:");
	scanf("%d",&n);
	initialize();
	do{
		printf("\n menu:\n");
		printf("1.bit vector \n");
		printf("2.create new file\n");
		printf("3.show directory\n");
		printf("4.exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:showbv(n);
			       break;
			case 2:createfile();
			       break;
			case 3:displaydir();
			       break;
			case 4:printf("Exiting.....");
			       break;
			default: printf("Eror:invalid choice\n");
				 break;
		}
	}

		while(choice!=4);
		return 0;
	}
