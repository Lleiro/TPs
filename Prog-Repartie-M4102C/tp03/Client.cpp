#include <iostream>
#include <string>
#include <chrono>
#include <boost/asio.hpp>

#include "Client.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

Client::Client(std::string nom, unsigned short n_port)
:sock(service_es)
{
  boost::asio::ip::tcp::resolver requeteur(service_es);
  boost::asio::ip::tcp::resolver::query requete(nom,to_string(n_port));
   //attention: chaîne
  boost::asio::ip::tcp::resolver::iterator iter = requeteur.resolve(requete);// on prend la 1ère adresse IP// (dans le cas où le DNS en donne plusieurs)
  boost::asio::ip::tcp::endpoint point_distant=*iter;
  
  //--TODO-- à compléter : affichage du résultat de la résolution DNS --TODO--/
  cout << " Résultat de la résolution DNS : " << point_distant << endl;

  cout<<"Tentative de connexion au serveur " << "..."<<endl;
  //--TODO-- à compléter : connexion au serveur --TODO--/
  sock.connect(point_distant);
  //----------------------------------------------------/
  cout<<"Connexion OK"<<endl;

  //--TODO-- à compléter : affichage des paramètres IP du client --TODO--/
  cout << "@IP : " << sock.local_endpoint() << endl ;
  //---------------------------------------------------------------------/
}

void Client::dialogue_avec_serveur(void)
{
  cout<<"Réception d'un entier..."<<endl;
  unsigned long entier_recu = EnvoiReception::recevoir_entier(sock);
  cout<<"Le serveur a envoyé l'entier "+to_string(entier_recu)<<endl;

  string chaine_recue =EnvoiReception::recevoir_chaine(sock);
  cout<<"Le serveur a envoyé la chaîne : "<<chaine_recue<<endl;

  // on attend un peu avant de fermer la connexion TCP
  sleep(3000); // sleep() est plus simple et ne nécessite pas d'inclure <thread>
}
