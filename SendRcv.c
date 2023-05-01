#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, value, num_proc;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    value = rank + 1000;

    /* On suppose avoir exactement 2 processus */
    num_proc = (rank + 1) % 2;

    MPI_Sendrecv(&value, 1, MPI_INT, num_proc, 99, &value, 1, MPI_INT, num_proc, 99, MPI_COMM_WORLD, &status);

    printf("Moi, le processus %d, j'ai reçu %d du processus %d\n", rank, value, num_proc);

    MPI_Finalize();
    return 0;
}

