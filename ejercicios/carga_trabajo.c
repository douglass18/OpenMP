/*
    carga_trabajo.c (SERIE)
    Analizar los factores de aceleracion obtenidos en funcion de la carga de trabajo
    Tamanos: 10, 100, 1000, 10000, 100000 y 1000000

    Ejecutar la version serie;
    A continuacion, paralelizar el bucle y ejecutarlo con 4 y 8 hilos
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000      // tamano maximo del vector 
int A[N];

void main () 
{
  struct timespec  t0, t1;
  double  tex;
  int     i, j, k, tamv;

  printf ("\n Tamano del vector --->  ");
  scanf  ("%d", &tamv);
  for (i=0; i<tamv; i++) A[i] = i % 100;

  clock_gettime (CLOCK_REALTIME, &t0);

  // bucle a ejecutar en paralelo
  for (i=0; i<tamv; i++)
  for (j=0; j<1000; j++)
    A[i] = (A[i]*A[i] + 1) * (A[i]*A[i] - 1) + (j%2);

  clock_gettime (CLOCK_REALTIME, &t1);

  tex = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / (double)1e9;
  printf ("\n Tex. (ser.) = %1.3f ms\n", tex*1000);
}

