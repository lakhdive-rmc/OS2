MPI Program in which root process i.e process with rank 0 generate random numbers and Scatter
//this randorm number to all processes in MPI Communication World. Then each processor compute the product of local array.
//Then ruduces this local product to global product. The Global product is displayed by root process i.e rank 0 processor.

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAY_SIZE 16

int main(int argc, char** argv) {
    int rank, nump;
    int *array;
    long lprod= 1, gprod=1;
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nump);

    srand(time(NULL));

    array = (int*) malloc(ARRAY_SIZE * sizeof(int));
	
    printf("\nprocessor no = %d and no of processor = %d\n",rank, nump); 
    if (rank == 0)
    {	    for (i = 0; i < ARRAY_SIZE; i++) {
	        array[i] = rand() % 10 + 1;
        }
//    	printf("\n Array Elemets are : \n");
//	for(i=0; i< ARRAY_SIZE; i++)
//		printf("%d\t", array[i]);
    }
MPI_Scatter(array, ARRAY_SIZE/nump, MPI_INT,array, ARRAY_SIZE/nump, MPI_INT, 0, MPI_COMM_WORLD);
for(i=0; i< ARRAY_SIZE/nump; i++)
                printf("%d\t", array[i]);
printf("\n");
for(i=0; i< ARRAY_SIZE/nump; i++)
		lprod = lprod * array[i];
printf("\nLocal product = %ld\n", lprod);
  MPI_Reduce(&lprod, &gprod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

  if (rank == 0) {
      printf("The product of an array is %ld\n", gprod);
}
    free(array);
    MPI_Finalize();
    return 0;
}
