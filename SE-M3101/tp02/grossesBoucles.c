#include <utmpx.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>

#define N_BASE 10
#define N_LONGUEUR 100000000

int main(int argc, char *argv[])
{
  int iterf,iterb,iterl,nb_forks,trace,foo=0;

  nb_forks=0;
  trace=0;

  for (int i=1; i<argc ;i++)
  {
    if (!strcmp(argv[i],"-trace"))
    {
      trace=1;
    }
    else if (!strcmp(argv[i],"-multi"))
    {
      nb_forks=8;
    }
    else
    {
      printf("Usage : grossesBoucles [-multi,-trace] \n");
      exit(1);
    }
  }

  printf("mon pid est %d \n",(int)getpid());

  for (iterf=0; iterf<nb_forks; iterf++)
  {
    fork();
  }

  for (iterb=0; iterb<N_BASE; iterb++)
  {
     for (iterl=0; iterl<N_LONGUEUR; iterl++)
     {
          foo += rand();
     }
    if (trace)
      printf("CPU: %d\n",sched_getcpu()+1);
  }

  return 0;
}

