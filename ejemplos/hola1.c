/*
    hola.c     PARA PARALELIZAR
    Tres versiones para generar hilos: (1) variable de entorno; (2) funcion; (3) clausula
    POR COMPLETAR  
***************************************************************************/

#include <stdio.h>
#include <omp.h>

#define N 12


void main ()
{
  int  tid, nth;        // identificador del hilo y numero de hilos
  int  i, A[N];

  for (i=0; i<N; i++) A[i] = 0;

  #pragma omp parallel private(nth, tid)
  {
    nth = omp_get_max_threads ();
    tid = omp_get_thread_num ();
    printf ("Hilo %d (%d) en ejecucion\n", tid, nth);

    A[tid] = tid + 10;
    printf ("         el hilo %d ha finalizado\n", tid);
  }

  for (i=0; i<N; i++) printf ("A(%d) = %d \n", i, A[i]);
  printf("\n fin de la region paralela\n\n");
}

