/*
   variables.c	definicion de variables
   PARA COMPLETAR    OpenMP
***************************************************************************/

#include <stdio.h>

#define N 4

void main ()
{
  int  tid, nth;
  int  i, j, A[N][N], inicio, fin;
  int  x = 0, z = 0, Amax = -1;

  // inicializar A
  for (i=0; i<N; i++)
  for (j=0; j<N; j++)
    A[i][j] = i+j;

  // for a paralelizar
  for (i=0; i<N; i++)
  for (j=0; j<N; j++)
  {
    x = A[i][j] * A[i][j];
    A[i][j] = (A[i][j] + x) % 17;
    z = z + x;
    if (Amax < A[i][j])  Amax = A[i][j];
  }

  // Mostrar la matriz y los resultados
  printf ("\n\n    --> matriz A[i][j]\n\n");
  for (i=0; i<4; i++)
  {
    for (j=0; j<4; j++) printf ("%8d", A[i][j]);
    printf ("\n");
  }
  printf ("\n    --> x %d, z %d, Amax %d\n\n", x, z, Amax);
}
