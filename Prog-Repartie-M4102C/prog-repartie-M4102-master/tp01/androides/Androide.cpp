#include <iostream>
#include <random>
#include <thread>
#include <chrono>

#include "Androide.hpp"
#include "Ecran.hpp"

using namespace std;
using namespace std::chrono;

int const Androide::COTE_ESPACE = 20; // l'espace à inspecter est un carré de 20 unités de côté

Androide::Androide(Ecran& ecran_, unsigned long num, unsigned long& lat) :
  ecran(ecran_),
  gen(num),
  numero(num),
  latence(lat)
{}

void Androide::operator()(void) {
  marche_aleatoire();
}

void Androide::maj_coord(int& coord)
{
  uniform_int_distribution<int> dis(-1,1);
  coord += dis(gen);
}

void Androide::marche_aleatoire(void)
{

  uniform_int_distribution<int> dis(5,5+COTE_ESPACE);
  int x = 5 + dis(gen);
  int y = 5 + dis(gen);

  for (int i = 0; i < 20; i++)
  {
    ecran.efface_car(x,y);
    maj_coord(x);
    maj_coord(y);
    // affiche en (x,y) le caractère correspondant  à l'entier numero
    ecran.affiche_car(static_cast<char>(numero+'0'),x,y);
    // suspend le thread durant un temps dépendant de l'entier latence
    this_thread::sleep_for(milliseconds(100)*(1+latence));
  }
  ecran.affiche_car('*',x+1,y);
}
