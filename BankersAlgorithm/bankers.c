#include <stdio.h>
int allocation[5][3] ={ {0, 1, 0}, {3, 0, 2}, {3, 0, 2},
                        {2, 1, 1}, {0, 0, 2} };

int max[5][3] ={ {7,5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2},
                        {4, 3, 3}  };
int available[3] = {2, 3, 0};
int n=5, m=3;
int need[5][3];
void computeneed();
void displaymatrix(int [][3]);
#define true 1
#define false 0
int ans[5];
int finish[5];
int main()
{
    int i, j;
    printf("\nAllocation Matrix\n");
    displaymatrix(allocation);
    printf("\nMax Matrix\n");
    displaymatrix(max);
    computeneed();
    printf("\nNeed Matrix\n");
    displaymatrix(need);
    checksystem();

    return 0;
}
 void computeneed()
    {
        int i, j;
        for(i=0; i< n; i++)
        {
               for(j=0; j<m; j++)
                    need[i][j] = max[i][j] - allocation[i][j];
        }
    }
void displaymatrix(int t[][3])
{ int i, j;
for(i=0; i< n; i++)
        {
                printf("\n");
                for(j=0; j<m; j++)
                    printf("\t%d",t[i][j]);
        }
}
int isfeasible(int pno)
{
   int cnt=0,j;
   for(j=0;j<m;j++)
       if(need[pno][j]<=available[j])
               cnt++;
   if(cnt==m)
         return 1;
   else
   return 0;
}
void checksystem()
{
    int cnt=0,flag,i,j;
    for(i=0;i<n;i++)
        finish[i]=false;
    while(true)
    {
    flag=false;
    for(i=0;i<n;i++)
        if(finish[i]==false)
          {
          printf("\n trying for p%d\n",i);
          if(isfeasible(i))
          {
          flag=true;
          printf("\n process p%d granted resources",i);
          finish[i]=true;
          ans[cnt++]=i; //safe sequence
          for(j=0;j<m;j++)
            available[j]=available[j]+allocation[i][j];
         }
        else
        printf("process p%d cannot be granted resources",i);
        }//end of if(!finish[i])
        if(flag==false)
                      break;
    }//end of while
    flag=true;
    for(i=0;i<n;i++)
        if(finish[i]==false)
            flag=false;
        if(flag==true)
                {
                     printf("\nSystem is in safe state\n");
                     printf("\nSafe sequence is as follows\n");
                     for(i=0;i<cnt;i++)
                              printf("p%d\t",ans[i]);
                }
                else
                printf("\nSystem is not in safe state\n");
}//end of function



