#include <iostream>
#include <string>
#include <chrono>
#include <boost/asio.hpp>

#include "Client.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

Client::Client(std::string nom, unsigned short n_port) :
  //--TODO-- à compléter : construction du socket --TODO--/
  sock(this->service_es)
  //------------------------------------------------------/
{
  //--TODO-- à remplacer : résolution DNS --TODO--/
  //(void)nom; (void)n_port;
  //boost::asio::ip::tcp::endpoint point_distant;
  //----------------------------------------------/

  //--TODO-- à compléter : affichage du résultat de la résolution DNS --TODO--/

  cout<<"Tentative de connexion au serveur "<<"..."<<endl;
  //--TODO-- à compléter : connexion au serveur --TODO--/
  boost::asio::ip::tcp::resolver requeteur(service_es);
  boost::asio::ip::tcp::resolver::query requete(nom, to_string(n_port)); //attention: chaîne
  boost::asio::ip::tcp::resolver::iterator iter = requeteur.resolve(requete);
  // on prend la 1ère adresse IP
  // (dans le cas où le DNS en donne plusieurs)
  boost::asio::ip::tcp::endpoint point_distant=*iter;
  sock.connect(point_distant);
  // maintenant on doit programmer les échanges...
  // la fermeture se fait toute seule à la fin du programme
  //----------------------------------------------------/
  cout<<"Connexion OK"<<endl;

  //--TODO-- à compléter : affichage des paramètres IP du client --TODO--/
  //---------------------------------------------------------------------/
}

void Client::dialogue_avec_serveur(void)
{
  cout<<"Réception d'un entier..."<<endl;
  unsigned long entier_recu=0;
  cout<<"Le serveur a envoyé l'entier "+to_string(entier_recu)<<endl;

  string chaine_recue;
  cout<<"Le serveur a envoyé la chaîne : "<<chaine_recue<<endl;

  // on attend un peu avant de fermer la connexion TCP
  sleep(3000); // sleep() est plus simple et ne nécessite pas d'inclure <thread>
}
