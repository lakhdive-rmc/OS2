//Third MPI Program in which root process i.e process with rank 0 generate random numbers and Scatter
//this randorm number to all processes in MPI Communication World. Then each processor display the local array.

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
	
    if (rank == 0)
    	{
    		for (i = 0; i < ARRAY_SIZE; i++) 
		        array[i] = rand() % 100;
	        printf("\n Array Elemets are : \n");
		for(i=0; i< ARRAY_SIZE; i++)
			printf("%d\t", array[i]);
	}
    MPI_Scatter(array, ARRAY_SIZE/nump, MPI_INT,array, ARRAY_SIZE/nump, MPI_INT, 0, MPI_COMM_WORLD);
    printf("\nLocal Array for Processor %d \n",rank);
	for(i=0; i< ARRAY_SIZE/nump; i++)
                printf("%d\t", array[i]);
	printf("\n");
    free(array);
    MPI_Finalize();
    return 0;
}
