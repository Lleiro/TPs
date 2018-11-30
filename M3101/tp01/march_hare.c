/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	/* pour printf() and co */
#include <sys/types.h>  /* pour getpid() and co */
#include <unistd.h>     /* pour getpid() and co */
#include <stdlib.h>	/* pour EXIT_ */

int main(void)
{
  int i=0;

  while (1)
  {
    printf("pid : %d, cup number %d\n", getpid(),i);
    i++;
    sleep(1);
  }

  return EXIT_FAILURE;
}
