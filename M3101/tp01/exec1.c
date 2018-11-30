/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <unistd.h>	/* pour execvp() */
#include <stdlib.h>	/* pour EXIT_* */
#include <stdio.h>	/* pour perror() */
#include <errno.h>	/* pour errno and co */
#include <sys/types.h>  /* pour pid_t */

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  char *arg[]={"march_hare",NULL};

  printf("Mon pid est %d\n",getpid());

  int res=execvp(arg[0],arg);
  if (res==-1) {perror("Echec execvp "); exit(errno);}

  /* si l'on arrive là, c'est qu'il y a eu un soucis */
  return EXIT_FAILURE;
}
