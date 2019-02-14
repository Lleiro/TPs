#include <iostream>
#include <random>
#include <thread>
#include <chrono>

#include "Androide.hpp"
#include "Ecran.hpp"

using namespace std;
using namespace std::chrono;

int const Androide::COTE_ESPACE = 20; // l'espace à inspecter est un carré de 20 unités de côté

//--TODO-- à remplacer et compléter --TODO--/
Androide::Androide(unsigned long numero_, unsigned long latence_, Ecran& ecran_) :

  ecran(ecran_),
  m_latence(latence_),
  m_numero(numero_),
  gen(numero_)
{}
//-----------------------------/


void Androide::operator()(void){
  marche_aleatoire(m_numero, m_latence);
}



void Androide::maj_coord(int& coord)
{
  uniform_int_distribution<int> dis(-1,1);
  coord += dis(gen);
}

void Androide::marche_aleatoire(unsigned long numero, unsigned long latence)
{
  //--TODO-- à supprimer --TODO--/
  //unsigned long numero = 0;
  //unsigned long latence = 0;
  //-----------------------------/

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
