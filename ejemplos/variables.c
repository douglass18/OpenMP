/*
   variables.c	definicion de variables
   PARA COMPLETAR    OpenMP
***************************************************************************/

#include <stdio.h>
#include <omp.h>

#define N 4

void main ()
{
  int  tid, nth;
  int  i, j, A[N][N], inicio, fin;
  int  x = 0, z = 0, zpar = 0, Amax = -1;


  for (i=0; i<N; i++)
  for (j=0; j<N; j++)
    A[i][j] = i+j;

  #pragma omp parallel default (none)
  {
    tid  = omp_get_thread_num ();
    nth = omp_get_max_threads ();

    inicio = tid * N / nth;
    fin = (tid+1) * N / nth;
 
    printf ("\n hilo %d (%d) -- inicio = %d, fin = %d", tid, nth, inicio, fin);

    zpar = 0;

    for (i=inicio; i<fin; i++)
    for (j=0; j<N; j++)
    {
      x = A[i][j] * A[i][j];
      A[i][j] = (A[i][j] + x) % 17;
      zpar = zpar + x; 
      if (Amax < A[i][j])  Amax = A[i][j];
    }
    z = z + zpar;
  }

  printf ("\n\n    --> matriz A[i][j]\n\n");
  for (i=0; i<4; i++) 
  {
    for (j=0; j<4; j++) printf ("%8d", A[i][j]);
    printf ("\n");
  }
  printf ("\n    --> x %d, zpar %d, z %d, Amax %d\n\n", x, zpar, z, Amax);
}

