#include <iostream>
#include <iomanip>

#include "RendezVous.hpp"

using namespace std;

//--TODO-- à compléter --TODO--/
RendezVous::RendezVous(const unsigned long nb_threads_) :
  nb_threads(nb_threads_), nb_attente(0)
{}

RendezVous::~RendezVous()
{}

void RendezVous::rvReveilleurUnique(void)
{
  std::unique_lock<mutex> mon_verrou(mon_mutex);
  if (nb_attente < nb_threads-1) { // Il manque des threads
    nb_attente++;
    ma_condition.wait(mon_verrou);
  } else { // Tous les autres threads attendent, on peut tous les réveiller
    nb_attente = 0;
    ma_condition.notify_all();
  }
}

void RendezVous::rvCascade(void)
{}

//-----------------------------/

void RendezVous::afficher(const unsigned long numero, const string& message, const unsigned long num_rendez_vous)
{
  const int largeur = static_cast<int>(message.size()+5);
  lock_guard<mutex> verrou(mutex_flux_sortie);

  for (unsigned long i=0; i < nb_threads; i++)
    if (i == numero)
      cout << setw(2) << numero << message << num_rendez_vous << " |";
    else
      cout << setw(largeur) << "|";
  cout << endl;
}
