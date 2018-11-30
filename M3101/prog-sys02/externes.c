/*--------------------------------------------------------------------------
 * headers à inclure afin de pouvoir utiliser divers appels systèmes
 * -----------------------------------------------------------------------*/
#include <stdio.h>     // pour printf() and co
#include <stdlib.h>    // pour exit()
#include <errno.h>     // pour errno and co
#include <unistd.h>    // pour pipe
#include <sys/types.h> // pour avoir pid_t
#include <signal.h>    // pour sigaction
#include <string.h>    // pour avoir strcmp and co

#include <sys/wait.h>  // pour avoir wait and co

/*--------------------------------------------------------------------------
 * header à inclure pour constantes et types spéciaux
 * -----------------------------------------------------------------------*/
#include "jobs.h"
#include "externes.h"

/*-------------------------------------------------------------------------------
 * Macro pour éviter le warning "unused parameter" dans une version intermédiaire
 * -----------------------------------------------------------------------------*/
#define UNUSED(x) (void)(x)


/*--------------------------------------------------------------------------
 * Affiche dans /dev/pts/2, la table des fichiers ouverts du processus courant (debug)
 * -----------------------------------------------------------------------*/
__attribute__((used)) static void afficher_table_fichiers(int num_comm)
{
  char commande[40];
  // attente proportionnelle au numéro du fils pour éviter le mélange des lignes
  sleep((unsigned int)num_comm);

  // affichage redirigé dans un autre terminal (à adapter)
  sprintf(commande,"ls -l /proc/%d/fd/ > /dev/pts/2",getpid());
  system(commande);
}


/*--------------------------------------------------------------------------
 * crée un fils pour exécuter la commande ligne_analysee->commandes[num_comm]
 * enregistre son pid dans job->pids[num_comm]
 * le fils définit ses handlers à différents signaux grâce à sig
 * -----------------------------------------------------------------------*/
static void execute_commande_dans_un_fils(job_t *job,int num_comm, ligne_analysee_t *ligne_analysee, struct sigaction *sig)
{
  // TODO : supprimer les lignes suivantes et compléter la procédure
  UNUSED(job); UNUSED(num_comm); UNUSED(ligne_analysee); UNUSED(sig);
  pid_t res_f = fork();
  printf("%d\n", fils);

  if (res_f == -1){
    perror("Echec fork");
    exit(errno);
  } else if(res_f != 0){
    int recupJob = job->pids[num_comm];
    char * recupLigne = ligne_analysee->commandes[num_comm];
    printf("%d\n", recupJob);
    printf("%s\n",*recupLigne );
  }


}

/*--------------------------------------------------------------------------
 * Fait exécuter les commandes de la ligne par des fils
 * -----------------------------------------------------------------------*/
void executer_commandes(job_t *job, ligne_analysee_t *ligne_analysee, struct sigaction *sig)
{
  // recopie de la ligne de commande dans la structure job
  strcpy(job->nom,ligne_analysee->ligne);

  // on lance l'exécution de la commande dans un fils
  execute_commande_dans_un_fils(job,0,ligne_analysee, sig);

  // TODO : à compléter

  // on ne se sert plus de la ligne : ménage
  *ligne_analysee->ligne='\0';
}
