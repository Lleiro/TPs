#include <iostream>

#include "Carrefour.hpp"


using namespace std;

Carrefour::Carrefour()
{
  voie_verte = voie_principale;
  automobile_engagee = false;
}

void Carrefour::entrer_dans_carrefour(unsigned int voie)
{
  std::unique_lock<mutex> verr(mon_mutex); // Permet de wait()

  while ((voie != voie_verte) || automobile_engagee) { // Blocage sa voie est bloquée ou une automobile est en train de traverser le carrefour
    cond_voies[voie].wait(verr);
  }
  
  automobile_engagee = true;
}

void Carrefour::sortir_du_carrefour(unsigned int) // on n'utilise pas le paramètre dans cette version
{
  std::lock_guard<mutex> verr(mon_mutex); // SC jusqu'à la fin de portée

  automobile_engagee = false;
  
  cond_commutation.notify_one();
  cond_voies[voie_verte].notify_one();
}

void Carrefour::basculer_sur(unsigned int nouvelle_voie_verte)
{
  std::unique_lock<mutex> verr(mon_mutex);

  afficherMessageCommutation(voie_verte, " FEU ORANGE");
  
  if (automobile_engagee) {
    cond_commutation.wait(verr);
  }
  
  afficherMessageCommutation(voie_verte, " FEU ROUGE");

  voie_verte = nouvelle_voie_verte;

  afficherMessageCommutation(voie_verte, " FEU VERT");
  
  cond_voies[voie_verte].notify_one();
}

const string nom_voie[Carrefour::nb_voies]={"PRINCIPALE","SECONDAIRE"};

void Carrefour::afficherMessageCommutation(unsigned int voie, string message)
{
  lock_guard<mutex> verrou(mutex_affichage);
  cout << nom_voie[voie] << message << endl;
}

void Carrefour::afficherMessageAuto(unsigned int voie, unsigned long numero, string message)
{
  lock_guard<mutex> verrou(mutex_affichage);
  cout << nom_voie[voie] << " " << numero << message << endl;
}
