#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

#include <random>
#include "Ecran.hpp"

// Classe avec opérateur parenthèses défini
class Androide
{
public :
  //--TODO-- à remplacer et compléter --TODO--/
  Androide(unsigned long numero_, unsigned long latence_, Ecran& ecran_);
  //-----------------------------/
  void operator()(void);

public :
  static int const COTE_ESPACE; // l'espace à inspecter est un carré de COTE_ESPACE unités de côté

private :
  //--TODO-- à compléter --TODO--/
  //-----------------------------/
  Ecran& ecran;
  unsigned long m_latence;
  unsigned long m_numero;
  std::default_random_engine gen;  // générateur aléatoire


  void maj_coord(int& coord);
  void marche_aleatoire(unsigned long numero, unsigned long latence);
};

#endif // MONTHREAD_HPP_
