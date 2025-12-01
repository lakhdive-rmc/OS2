//First MPI Program which print number of processor and rank of each processor

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int rank, nump;

    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nump);


    printf("\nprocessor no = %d and no of processor = %d\n",rank, nump); 
    if (rank == 0)
    	{	
      printf("I am root process with rank 0");
	}
    MPI_Finalize();
    return 0;
}
