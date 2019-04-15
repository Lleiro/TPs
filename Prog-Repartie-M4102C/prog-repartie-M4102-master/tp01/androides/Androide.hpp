#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

#include <random>
#include "Ecran.hpp"

// Classe avec opérateur parenthèses défini
class Androide
{
public :
  Androide(Ecran& ecran_, unsigned long num, unsigned long& lat);
  void operator()(void);
  
public :
  static int const COTE_ESPACE; // l'espace à inspecter est un carré de COTE_ESPACE unités de côté

private :
  Ecran& ecran;
  std::default_random_engine gen;  // générateur aléatoire
  unsigned long numero;
  unsigned long& latence; // Passage par référence (en cas de modification dans la fct main)


  void maj_coord(int& coord);
  void marche_aleatoire(void);
};

#endif // MONTHREAD_HPP_
