/*
    num_hilos.c (SERIE)
    Analizar el factor de aceleracion en funcion del numero de hilos 
    PARA PARALELIZAR 
    Hilos: 2, 4, 8, 16, 32, 64
*******************************************************/
#include <stdio.h>
#include <time.h>
#include <omp.h> //incluir la libreria omp
#define N 800
#define ITERACIONES 5

int  A[N][N], B[N][N], C[N][N];

void Tiempo_Eje(char *pTexto, struct timespec *pt0, struct timespec *pt1)
{
  double  tex;

  tex = (pt1->tv_sec - pt0->tv_sec) + (pt1->tv_nsec - pt0->tv_nsec) / (double)1e9;
  printf ("%s = %10.3f ms\n", pTexto, tex*1000);
}

// PROGRAMA PRINCIPAL
void main ()
{
  int  i, j, k, num_it, sum_diag = 0;;
  struct timespec  t0, t1;

  for (num_it=0; num_it<ITERACIONES; num_it++)
  {
    // valores iniciales
    for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    {
      A[i][j] = (i % 5) - 2;
      B[i][j] = (j % 7) - 4;
    }

    clock_gettime (CLOCK_REALTIME, &t0);

    // bucle a ejecutar en paralelo
    #pragma omp parallel for private(i,j,k) schedule (static)
    for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    {
       C[i][j] = 0;
       for (k=0; k<N; k++)
         C[i][j] += A[i][k] * B[k][j];
    }  
  
    clock_gettime (CLOCK_REALTIME, &t1);
    Tiempo_Eje ("Tex: ", &t0, &t1);
  }

  for (i=0; i<N; i++) sum_diag += C[i][i];
  printf ("\n suma diagonal = %d\n", sum_diag);
  printf(" nth:%d\n",omp_get_max_threads());
}

