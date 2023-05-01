#include "mpi.h"
#include <stdio.h>

int rang, valeur, nb_processus, num_proc_suivant, num_proc_precedent;
MPI_Status status;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nb_processus);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);
    num_proc_precedent = (nb_processus + rang - 1) % nb_processus;
    num_proc_suivant = (rang + 1) % nb_processus;
    valeur = rang + 1000;
    MPI_Send(&valeur, 1, MPI_INT, num_proc_suivant, 99, MPI_COMM_WORLD);
    MPI_Recv(&valeur, 1, MPI_INT, num_proc_precedent, 99, MPI_COMM_WORLD, &status);
    printf("Moi, le processus %d, j'ai reçu %d du processus %d\n", rang, valeur, num_proc_precedent);
    MPI_Finalize();
}

