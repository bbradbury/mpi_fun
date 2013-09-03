
/*
   "Hello World" MPI Test Program
 */
#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "mpi_fun/pi/pi_calc.h"

#define BUFSIZE 128
#define TAG 0

#define TOTAL_ITERATIONS 100000000

int main(int argc, char *argv[])
{
  char idstr[32];
  char buff[BUFSIZE];
  int numprocs;
  int myid;
  int i;
  MPI_Status stat;
  /* MPI programs start with MPI_Init; all 'N' processes exist thereafter */
  MPI_Init(&argc,&argv);
  double result;
  double finalResult;
  /* find out how big the SPMD world is */
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  /* and this processes' rank is */
  MPI_Comm_rank(MPI_COMM_WORLD,&myid);

  int iterations_per_process = TOTAL_ITERATIONS / (numprocs - 1);

  /* At this point, all programs are running equivalently, the rank
     distinguishes the roles of the programs in the SPMD model, with
     rank 0 often used specially... */
  if(myid == 0)
  {
    printf("%d: We have %d processors\n", myid, numprocs);
    for(i=1;i<numprocs;i++)
    {
      sprintf(buff, "Hello %d! ", i);
      MPI_Send(buff, BUFSIZE, MPI_CHAR, i, TAG, MPI_COMM_WORLD);
    }
    for(i=1;i<numprocs;i++)
    {
      printf("Waiting for %d\n", i);
      //TODO: should be MPI_DOUBLE, no?
      MPI_Recv(&result, sizeof(result), MPI_CHAR, i, TAG, MPI_COMM_WORLD, &stat);
      if(i == 1)
        finalResult = result;
      else
        finalResult = (finalResult + result) / 2;
      printf("(%d): got from %d: %F\n", myid,i, result);
    }
    printf("PI IS %.20F\n", finalResult);
  }
  else
  {
    mpi_fun::pi::PiCalc piCalc(iterations_per_process);
    /* receive from rank 0: */
    MPI_Recv(buff, BUFSIZE, MPI_CHAR, 0, TAG, MPI_COMM_WORLD, &stat);
    sprintf(idstr, "Processor %d ", myid);
    strncat(buff, idstr, BUFSIZE-1);
    strncat(buff, "reporting for duty\n", BUFSIZE-1);
    printf("Worker %d (%p) running %d iterations...\n", myid, &piCalc, piCalc.get_iterations());
    result = piCalc.run();
    printf("Sizeof result: %d\n", sizeof(result));
    printf("Worker %d got result: %.20F\n", myid, result);

    //TODO: should be MPI_DOUBLE, no?
    MPI_Send(&result, sizeof(result), MPI_CHAR, 0, TAG, MPI_COMM_WORLD);
  }

  /* MPI programs end with MPI Finalize; this is a weak synchronization point */
  MPI_Finalize();
  return 0;
}
