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
#include <sys/wait.h>   /* pour wait() and co */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  pid_t res_f;
  char reponse;

  res_f=fork();
  if (res_f==-1) {perror("Echec fork "); exit(errno); }

  if (res_f==0)
  {
    printf("pid : %d \n", getpid());
  }
  else
  {
    waitpid(res_f, NULL, 0);
    int resu=scanf("%c",&reponse);
    if (resu==EOF) {perror("Echec scanf "); exit(errno); }
  }

  return EXIT_SUCCESS;
}
