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

    for (int i = 0; i < longueur_tranche; i++) {
        valeurs[i] = 1000 + rang * longueur_tranche + i;
    }

    MPI_Gather(valeurs, longueur_tranche, MPI_FLOAT, donnees, longueur_tranche, MPI_FLOAT, 2, MPI_COMM_WORLD);

    if (rang == 2) {
        printf("Moi, le processus 2, j’ai reçu ");
        for (int i = 0; i < nb_valeurs; i++) {
            printf("%f ", donnees[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}

