#ifndef RESSOURCE_PROTEGEE_HPP_
#define RESSOURCE_PROTEGEE_HPP_

//--TODO-- à compléter --TODO--/
#include <atomic>
#include <mutex>
//-----------------------------/

class RessourceProtegee
{
public :
  RessourceProtegee();

  // méthodes manipulant de façon sûre les variables partagées entre les threads
  void incrementer_avec_une_sc(unsigned long numero, unsigned long nb_iterations);
  void incrementer_avec_pls_sc(unsigned long numero, unsigned long nb_iterations);

  // méthode donnant un accès non protégé à la ressource
  unsigned long acces_non_protege(void);

private :
  // variables partagées entre les threads
  //--TODO-- à modifier et compléter --TODO--/
  //std::atomic<unsigned long> total;
  unsigned long total;
  std::mutex monMutex;
  //-----------------------------/
};

#endif // RESSOURCE_PROTEGEE_HPP_
