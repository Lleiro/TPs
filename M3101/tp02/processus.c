#include <sched.h>
#include <unistd.h>
#include <stdio.h>	/* pour printf() and co */
#include <stdlib.h>
#include <errno.h>	/* pour errno and co */
#include <sys/types.h>
#include <sys/wait.h>

static void message_voyant(void)
{
  for (int i=0; i<5; i++) printf("\n");
  for (int i=0; i<44; i++) printf("%c",'*');
  printf("\n*  ALERTE!!!"); for (int i=0; i<31; i++) printf("%c",' '); printf("*\n");
  printf("*"); for (int i=0; i<42; i++) printf("%c",' '); printf("*\n");
  perror("*  ECHEC execvp ");
  printf("*"); for (int i=0; i<42; i++) printf("%c",' '); printf("*\n");
  printf("*  ALERTE!!!"); for (int i=0; i<31; i++) printf("%c",' '); printf("*\n");
  for (int i=0; i<44; i++) printf("%c",'*');
  for (int i=0; i<5; i++) printf("\n");
}

static void fils(int numero)
{
  int res_e;

  if (numero==0)
  {
    char* arg[]={"bin-gcc/grossesBoucles","-multi",NULL};
    res_e=execvp(arg[0],arg);
    if (res_e==-1) {message_voyant(); exit(errno); }
  }
  else
  {
    int res=nice(0);
    if(res==-1) {perror("Echec nice "); exit(errno); }
    char* arg[]={"mpv","/users/info/pub/s3/M3101/data/bbc.mp3",NULL};
    res_e=execvp(arg[0],arg);
    if (res_e==-1) {perror("Echec execvp "); exit(errno); }
  }

  exit(1);
}


int main(void)
{
  pid_t pid[2];	    // pids des fils

  for (int i=0; i<2; i++)
  {
    pid[i]=fork();
    if (pid[i]==0)
    {
      fils(i);
    }
  }

  for (int i=0;i<2;i++)
  {
    waitpid(pid[i],NULL,0);
  }

  return 0;
}
