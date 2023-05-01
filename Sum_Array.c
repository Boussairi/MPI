#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
int main(int argc, char** argv) {
    int my_rank, num_procs;
    int array[ARRAY_SIZE];
    int local_sum = 0, global_sum = 0;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    // Le processus 0 initialise le tableau d'entiers
    if (my_rank == 0) {
        printf("Entrez %d valeurs entières : \n", ARRAY_SIZE);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            scanf("%d", &array[i]);
        }}
    // Le processus 0 envoie une tranche du tableau à chaque processus
    MPI_Bcast(array, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);
    // Chaque processus calcule la somme des valeurs de sa tranche
    int local_start = my_rank * (ARRAY_SIZE / num_procs);
    int local_end = local_start + (ARRAY_SIZE / num_procs);
    for (int i = local_start; i < local_end; i++) {
        local_sum += array[i];}
    // Les sommes locales sont réduites en une somme globale sur le processus 0
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        printf("La somme des valeurs est : %d\n", global_sum); }
    MPI_Finalize();
    return 0;}

