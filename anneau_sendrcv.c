#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int size, rank;
    int value, recv_value;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size != 7) {
        printf("Le programme doit être lancé avec 7 processus.\n");
        MPI_Finalize();
        return 0;
    }

    value = rank + 1000;
    MPI_Sendrecv(&value, 1, MPI_INT, (rank + 1) % 7, 99, &recv_value, 1, MPI_INT, (rank + 6) % 7, 99, MPI_COMM_WORLD, &status);

    printf("Processus %d : j'ai reçu la valeur %d du processus %d\n", rank, recv_value, (rank + 6) % 7);

    MPI_Finalize();
    return 0;
}

