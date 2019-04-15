#include <iostream>
#include <vector>
#include <thread>

#include "Tableau.hpp"
#include "TableauMutex.hpp"
#include "TableauCond.hpp"
#include "Calculateur.hpp"
#include "MonThread.hpp"

using namespace std;

static void usage(const char* nom)
{
  cerr << "Usage : " << nom << " {mutex|cond} nb_iter" << endl;
}

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  const unsigned long nb_iter = stoul(argv[2]);

  // pointeur vers le tableau aléatoire partagé avec ou sans outils de synchronisation
  Tableau* tableau;

  // création du tableau
  if (string(argv[1])=="mutex")
  {
    tableau = new TableauMutex();
  }
  else if (string(argv[1])=="cond")
  {
    tableau = new TableauCond();
  }
  else
  {
      usage(argv[0]);
      throw;
  }

  // création du calculateur
  Calculateur calculateur(nb_iter,*tableau);

  // création des threads
  vector<thread> mes_threads;
  for (unsigned long i=0; i < Tableau::NB_VALEURS; i++)
    mes_threads.push_back(thread(MonThread(i,calculateur)));

  // attente des threads
  for (unsigned long i=0; i < Tableau::NB_VALEURS; i++)
    mes_threads.at(i).join();

  // vérification de l'état final du tableau
  tableau->afficher_etat_final();

  delete tableau;

  return EXIT_SUCCESS;
}
