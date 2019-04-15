#include <iostream>

#include "TamponCond.hpp"
#include "Element.hpp"

using namespace std;

TamponCond::TamponCond(const unsigned long taille_, EcranManchots& ecran_) :
  Tampon(ecran_), taille(taille_)
{}

void TamponCond::deposer_element(Element e)
{
    ecran.dessiner_creer_manchot(e);
    // ATTENTION : Ne rien écrire avant la ligne précédente

    std::unique_lock<mutex> verrou(mon_mutex);
    while(tampon.size() == taille) {
        var_cond_prod.wait(verrou);
    }

    //-- NE PAS TOUCHER : code qui teste la bonne réalisation de la sychronisation --/
    if (tampon.size() == taille)
    {
      ecran.~EcranManchots();
      cerr << "Tentative de dépôt alors que le tampon est plein." << endl;
      throw;
    }
    //-- FIN DE CODE A NE PAS TOUCHER --/

    ecran.dessiner_deposer_manchot(e);

    tampon.push_front(e);

    var_cond_cons.notify_one(); // On réveille un consommateur en attente

}

Element TamponCond::retirer_element(const unsigned long numcons, const unsigned long nummanchot)
{
    ecran.dessiner_demander_manchot(static_cast<int>(numcons),static_cast<int>(nummanchot));
    Element e = 0;
    // ATTENTION : Ne rien écrire avant les lignes précédentes
        
    std::unique_lock<mutex> verrou(mon_mutex);
    while (tampon.empty()) {
        var_cond_cons.wait(verrou);
    }
    

    //-- NE PAS TOUCHER : code qui teste la bonne réalisation de la sychronisation --/
    if (tampon.empty())
    {
      ecran.~EcranManchots();
      cerr << "Tentative de retrait alors que le tampon est vide." << endl;
      throw;
    }
    //-- FIN DE CODE A NE PAS TOUCHER --/

    e = tampon.back();
    tampon.pop_back();
    e.setNumCons(numcons);

    ecran.dessiner_retirer_manchot(e,static_cast<int>(nummanchot));

    var_cond_prod.notify_one(); // On réveille un producteur en attente
  
  return e;
}
