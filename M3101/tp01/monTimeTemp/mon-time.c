#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

#define MILLION 1000000.0

int main(int argc, char* argv[])
{
  struct timeval t1, t2;
  // on prend la mesure du temps avant le fork()
  // pour avoir des mesures plus stables
  // à compléter : 1ère mesure du temps dans t1

  // à compléter : création d'un processus fils et test d'échec

  // à compléter : test père/fils
  if (...)
  { // on est dans le fils
    // à compléter : vérification du nombre d'arguments et exécution du fils
  }
  else
  { // on est dans le père
    // à compléter : attente de la fin du fils
    // à compléter : 2ème mesure du temps dans t2

    printf("fin du fils\n");

    // à compléter : calcul du temps
    double temps_ecoule = 0.0;
    printf("temps écoulé : %lf secondes\n", temps_ecoule);
  }

  return EXIT_SUCCESS;
}
