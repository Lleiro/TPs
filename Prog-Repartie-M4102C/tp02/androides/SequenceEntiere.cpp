#include <thread>
#include <chrono>
//--TODO-- à compléter --TODO--/
//-----------------------------/

#include "SequenceEntiere.hpp"

using namespace std;

SequenceEntiere::SequenceEntiere(unsigned int numero_initial) :
  numero(numero_initial)
{}

unsigned int SequenceEntiere::nouveau_numero(void)
{
  //--TODO-- à compléter --TODO--/
  lock_guard<mutex> verrou(monMutex);
  unsigned int resultat = numero;
  // ne pas enlever cette temporisation
  this_thread::sleep_for(chrono::milliseconds(100));
  numero++;
  //-----------------------------/
  return resultat;
}
