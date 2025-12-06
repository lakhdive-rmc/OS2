//Each file is a linked list of blocks scattered anywhere on the disk.
//Eliminates fragmentation but provides slower access due to pointer traversal.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct dirfile
{
	char fname[20];
	int length;
	int indexblock;
	int a[10];
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



int findFreeBlock() {
    for (int i = 0; i < n; ++i) {
        if (bv[i] == 1) {
            return i;
        }
    }
    return -1; // No free block found
}
void allocateBlocks(int length) {
	int allocatedblk=0;
        int blocknum;
	direntry[totalfile].indexblock=-1;
        while (allocatedblk < length) {
	        blocknum = findFreeBlock();
        	if (blocknum == -1) {
		            printf("Error: No free space available!\n");
		            return ;
			        }
			
			
		// Allocate block
		bv[blocknum] = 0;

		if (direntry[totalfile].indexblock == -1)
		{
			direntry[totalfile].indexblock = blocknum;
			 
		}
		else
		{
			direntry[totalfile].a[allocatedblk]=blocknum;
       			allocatedblk++;
		//	printf("\nManisha");
		}
    }
   }
        
void createfile()
{
	char fname[10];
	int length,blknum,k;
//	struct block * sblock=NULL;
	
	printf("\nEnter File Name : ");
	scanf("%s",&fname);
	printf("enter the length of file:");
	scanf("%d",&length);

	allocateBlocks(length);
        
  //      if (sblock == NULL) {
  //      	printf("File creation failed!\n");
    //    	return;
   //		}    
	printf("\n block allocated\n");
	used=used+length;
	
	k=totalfile++;
	strcpy(direntry[k].fname,fname);
	direntry[k].length = length;
}



void displaydir()
{
	int k,i=0;
	
	printf("\t filename\t start_block\n");
	for(k=0;k<totalfile;k++)
	{
		printf("%s",direntry[k].fname);
		printf("Index Block = %d",direntry[k].indexblock);
		printf("\tLength = %d",direntry[k].length);
		printf("\tBlocks: ");
		i=0;
	        while (i < direntry[k].length) {
		    printf("\t%d ",direntry[k].a[i] );
		    i++;
		  }
        	printf("\n\n");
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

