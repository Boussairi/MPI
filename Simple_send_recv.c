# include "mpi.h"
# include <stdio.h>
int myid, valeur;
MPI_Status status;
int main(int argc, char *argv[])
{
	MPI_Init (&argc , &argv) ;
	MPI_Comm_rank (MPI_COMM_WORLD,&myid);
	if (myid == 1) { valeur=1000;
		MPI_Send (&valeur,1,MPI_INT,5,99, MPI_COMM_WORLD);
	}
	else {
		if(myid == 5) {
			MPI_Recv (&valeur,1,MPI_INT,1,99, MPI_COMM_WORLD,&status);
			printf ("Moi, le processus 5 ,j’ai reçu %d du processus 1 \n", 							valeur);
	}}
	MPI_Finalize();
	}
