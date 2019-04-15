
#include "TableauCond.hpp"

using namespace std;

//--TODO-- à compléter --TODO--/
TableauCond::TableauCond()
{
  for(size_t i = 0; i < NB_VALEURS; i++)
  {
    vecteur_sync.push_back(false);
  }
  

}
//-----------------------------/

void TableauCond::reserver(const unsigned long numero, const unsigned long iter,
                           int& poids_somme, int& poids_multiplication)
{
  std::unique_lock<mutex> verr(mutex_sync);

  while ( vecteur_sync.at((numero == 0 ? NB_VALEURS-1 : numero-1)) ||
          vecteur_sync.at((numero == NB_VALEURS-1 ? 0 : numero+1)) )
  {
    conditions[numero].wait(verr);
  }

  vecteur_sync.at(numero) = true;

  verifier_une_reservation_par_iteration(numero, iter);

  recuperer_poids(iter,poids_somme,poids_multiplication);
}

void TableauCond::liberer(const unsigned long numero)
{
  std::lock_guard<mutex> verr(mutex_sync);

  vecteur_sync.at(numero) = false;

  conditions[(numero == 0 ? NB_VALEURS-1 : numero-1)].notify_one();
  conditions[(numero == NB_VALEURS-1 ? 0 : numero-1)].notify_one();
}
