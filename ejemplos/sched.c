/*
   sched.c
   Ejemplo para analizar distintas estrategias de planificacion
   Reparto mediante una variable de entorno (Runtime)
   Por ejemplo:    export OMP_SCHEDULE="static,4"
***************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <omp.h>

#define N 40


void main ()
{
  int  tid;
  int  i, A[N];

  for (i=0; i<N; i++) A[i] = -1;


  #pragma omp parallel for private (tid) schedule (runtime)
  for (i=0; i<N; i++)
  {
    tid = omp_get_thread_num ();

    A[i] = tid;
    usleep (2);
  }

  for (i=0; i<N/2; i++)  printf (" %2d", i);
  printf ("\n");
  for (i=0; i<N/2; i++)  printf (" %2d", A[i]);
  printf ("\n\n\n");
  for (i=N/2; i<N; i++)  printf (" %2d", i);
  printf ("\n");
  for (i=N/2; i<N; i++)  printf (" %2d", A[i]);
  printf ("\n\n");
}

