/*
  secciones.c
  Reparto de trabajo mediante secciones/funciones. Ejemplo con tres secciones.
  Ejecutar con 1, 2 y 3 hilos
***************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NA 1800000
#define NB 2000000
#define NC 2500000

double fun (int N)
{
  usleep (N);
  return (N/100000);
}

void main ()
{
  int     tid = -1, nth;
  double  A, B, C, D;;

  double  tex;
  struct timespec  t0, t1;

  clock_gettime (CLOCK_REALTIME, &t0);

  #pragma omp parallel private (tid, nth)
  {
    tid = omp_get_thread_num ();
    nth = omp_get_num_threads ();
    if (tid == 0) printf ("\n  Ejecucion paralela, %d hilos\n", nth);

    #pragma omp sections
    {
      #pragma omp section
      {
        A = fun (NA);
      }
      #pragma omp section
      {
        B = fun (NB);
      }
      #pragma omp section
      {
        C = fun (NC);
      }
    }
  }

  D = A + B + C;

  clock_gettime (CLOCK_REALTIME, &t1);
  printf ("\n  Resultados A = %.2f  B = %.2f  C = %.2f ---> D = %.2f", A, B, C, D);

  tex = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / (double)1e9;
  printf ("\n\n  Tex = %1.3f ms\n\n", tex*1000);
}

