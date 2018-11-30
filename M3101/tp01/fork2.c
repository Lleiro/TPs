/*--------------------------------------------------------------------------
 * Programme à compléter pour expérimenter l'usage de fork
 * -----------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>	/* pour exit() */
#include <errno.h>	/* pour errno and co */
#include <unistd.h>	/* pour fork() */
#include <sys/types.h>  /* pour pid_t */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  pid_t res;
  pid_t res2;

  res=fork();
  res2=-1;
  if (res==-1) {perror("Echec fork "); exit(errno); }

  /* --------- à compléter ----------- */
  int generation = 0;

  if (res == 0) {
    generation ++;

      res = fork();
      res2 = fork();
      if (res == 0) generation ++;
  }


  if (res2 == -1) printf("%d : je suis %d fils de %d , res = %d, res2 = ?\n", generation, getpid(), getppid(), res);
  else printf("%d : je suis %d fils de %d , res = %d, res2 = %d\n", generation, getpid(), getppid(), res, res2);

  return 0;
}
