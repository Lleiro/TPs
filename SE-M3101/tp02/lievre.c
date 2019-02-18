/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>	/* pour exit() */
#include <errno.h>	/* pour errno and co */
#include <sys/types.h>  /* pour pid_t et open() */
#include <sys/stat.h>   /* pour open() */
#include <fcntl.h>      /* pour open() */
#include <unistd.h>     /* pour read(), close() et pause()*/

/*--------------------------------------------------------------------------
 * Fonction principale
 * -----------------------------------------------------------------------*/
int main(void)
{
  int desc, res_e;
  pid_t pid;
  char* arg[]={"bin-gcc/march_hare",NULL};

  desc = open("/tmp/vent",O_WRONLY);
  if (desc == -1) {perror("Echec open "); exit(errno); }

  /* à corriger */
  pid=0;

  ssize_t res=write(desc,&pid,sizeof(pid_t));
  if(res==-1) {perror("Echec write "); exit(errno); }
  close(desc);

  res_e=execvp(arg[0],arg);
  if (res_e==-1) {perror("Echec execvp "); exit(errno); }

  return EXIT_FAILURE;
}
