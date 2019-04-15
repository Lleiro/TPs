#include <thread>

#include "OutilsCond.hpp"

using namespace std;
using namespace std::chrono;

OutilsCond::OutilsCond()
{
    nb_lec = 0;
    nb_red = 0;
}

void OutilsCond::debut_lecture(void)
{
  unique_lock<mutex> verrou(mon_mutex);
  while (nb_red > 0) {
    ma_condition.wait(verrou);
  }
  nb_lec++;
}

void OutilsCond::fin_lecture(void)
{
  lock_guard<mutex> verrou(mon_mutex);
  nb_lec--;
  ma_condition.notify_one(); // notify_one car un seul rédacteur dispo après (limite le coût du réveil des threads)
}

void OutilsCond::debut_ecriture(void)
{
  unique_lock<mutex> verrou(mon_mutex);
  while (nb_lec > 0 || nb_red == 1) {
    ma_condition.wait(verrou);
  }
  nb_red++;
}

void OutilsCond::fin_ecriture(void)
{
  lock_guard<mutex> verrou(mon_mutex);
  nb_red--;
  ma_condition.notify_all(); // notify_all car possibilité de plusieurs lecteurs
}
