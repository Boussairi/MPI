#include <mpi.h>
#include <stdio.h>

#define nb_valeurs 128

int main(int argc, char *argv[])
{
    int rang, nb_processus, longueur_tranche;
    float valeurs[nb_valeurs], donnees[nb_valeurs];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nb_processus);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);

    longueur_tranche = nb_valeurs / nb_processus;

    if (rang == 2) {
        for (int i = 0; i < nb_valeurs; i++) {
            valeurs[i] = 1000 + i;
        }
    }

    MPI_Scatter(valeurs, longueur_tranche, MPI_FLOAT, donnees, longueur_tranche, MPI_FLOAT, 2, MPI_COMM_WORLD);

    printf("Moi, le processus %d, j'ai reçu %f ... %f du processus 2\n", rang, donnees[0], donnees[longueur_tranche-1]);

    MPI_Finalize();
    return 0;
}

