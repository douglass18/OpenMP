/*
    hola.c     PARA PARALELIZAR
    Generar hilos: (1) variable de entorno; (2) funcion; (3) clausula
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

  //  (1) el numero de hilos se controla con una variable de entorno: 12 hilos

  #pragma omp parallel private (tid, nth)
  {
    nth = omp_get_num_threads (); // nth = omp_get_max_threads ();
    tid = omp_get_thread_num ();
    printf ("Hilo %d (%d) en ejecucion\n", tid, nth);

    A[tid] = tid + 10;
    printf ("         el hilo %d ha finalizado\n", tid);
  }

  for (i=0; i<N; i++) printf ("A(%d) = %d \n", i, A[i]);
  printf("\n fin de la primera region paralela\n\n");

/*
  //  (2) el numero de hilos se controla mediante una funcion (completar): 8 hilos

  printf ("\n\n Num hilos  --->  ");
  scanf  ("%d", &nth);

  #pragma omp parallel private (tid)
  {
    tid = omp_get_thread_num ();
    printf ("hilo %d en ejecucion\n", tid);

    A[tid] = tid + 100;
    printf ("         el hilo %d ha finalizado\n", tid);
  }

  for (i=0; i<N; i++) printf ("A(%d) = %d \n", i, A[i]);
  printf("\n fin de la segunda region paralela\n\n");
*/

/*
  //  (3) el numero de hilos se controla mendiante una clausula (completar): 4 hilos

  #pragma omp parallel private (tid)
  {
    tid = omp_get_thread_num ();
    printf ("hilo %d en ejecucion\n", tid);

    A[tid] = tid + 1000;
    printf ("         el hilo %d ha finalizado\n", tid);
  }

  for (i=0; i<N; i++) printf ("A(%d) = %d \n", i, A[i]);
  printf("\n fin de la tercera region paralela\n\n");
*/
}

