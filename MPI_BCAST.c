#include "mpi.h"
#include <stdio.h>

int rang, valeur;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);

    if (rang == 2) 
    {
        valeur = rang + 1000;
    }
    
    MPI_Bcast(&valeur, 1, MPI_INT, 2, MPI_COMM_WORLD);
    
    printf("Moi, le processus %d, j’ai reçu %d du processus 2\n", rang, valeur);

    MPI_Finalize();
}

