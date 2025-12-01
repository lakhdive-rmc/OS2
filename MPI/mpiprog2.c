//Second MPI Program in which root process i.e process with rank 0 generate random numbers and display it.

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAY_SIZE 16

int main(int argc, char** argv) {
    int rank, nump;
    int *array;
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nump);

    srand(time(NULL));

    array = (int*) malloc(ARRAY_SIZE * sizeof(int));
	
    printf("\nprocessor no = %d and no of processor = %d\n",rank, nump); 
    if (rank == 0)
    	{
    		for (i = 0; i < ARRAY_SIZE; i++) 
		        array[i] = rand() % 100;
	        printf("\n Array Elemets are : \n");
		for(i=0; i< ARRAY_SIZE; i++)
			printf("%d\t", array[i]);
	}
    free(array);
    MPI_Finalize();
    return 0;
}
