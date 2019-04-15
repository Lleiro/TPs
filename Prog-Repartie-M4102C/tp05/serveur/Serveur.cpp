#include <iostream>

#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

Serveur::Serveur(unsigned short n_port)
//--TODO-- à remplacer : on initialise un socket d'écoute rattaché au port --TODO--/
{
  (void)n_port;
}
//---------------------------------------------------------------------------------/

[[noreturn]] void Serveur::attend_clients(void)
{
  //--TODO-- à compléter : afficher adresse IP et port locaux du socket d'écoute--TODO--/
  //------------------------------------------------------------------/

  unsigned long entier=42;

  // on va traiter plusieurs clients séquentiellement
  while(true) {

    //-TODO-- à compléter : déclaration d'un socket --TODO--/
    //------------------------------------------------------/

    cout<<"En attente d'un client..."<<endl;

    //--TODO-- à compléter : attendre une connexion TCP --TODO--/
    //----------------------------------------------------------/

    //--TODO-- à compléter : afficher adresse IP et n°port du client --TODO--/
    //--TODO-- à compléter : afficher adresse IP et n°port du socket de transfert --TODO--/
    //-----------------------------------------------------------------------/

    // on envoie un entier au client
    cout<<"Envoi de l'entier "<<entier<<"..."<<flush;
    sleep(2);
    cout<<"OK"<<endl;

    // on envoie une chaîne au client
    cout<<"Envoi d'une chaîne..."<<flush;
    sleep(2);
    cout<<"OK"<<endl;

    // on attend un peu avant de fermer la connexion TCP
    sleep(3000); // sleep() est plus simple et ne nécessite pas d'inclure <thread>

    entier++;
  }
}
