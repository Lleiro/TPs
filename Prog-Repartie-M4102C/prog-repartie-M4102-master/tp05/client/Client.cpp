#include <iostream>
#include <string>
#include <chrono>
#include <boost/asio.hpp>

#include "Client.hpp"
#include "EnvoiReception.hpp"

using namespace std;

Client::Client(std::string nom, unsigned short n_port) :
  //Construction du socket
  sock(service_es)
{
  //Résolution DNS
  boost::asio::ip::tcp::resolver requeteur(service_es);
  boost::asio::ip::tcp::resolver::query requete(nom, to_string(n_port));

  boost::asio::ip::tcp::resolver::iterator iter = requeteur.resolve(requete);

  // On récupère la première adresse IP (au cas où le DNS en renvoie plusieurs)
  boost::asio::ip::tcp::endpoint point_distant = *iter;


  // Affichage du résultat de la résolution DNS
  cout << "Paramètres IP serveur : " << point_distant << endl;

  cout << "Tentative de connexion au serveur " << "..." << endl;
  // Connexion au serveur
  sock.connect(point_distant);

  cout << "Connexion OK" << endl;

  // Affichage des paramètres IP du client
  cout << "Paramètres IP client : " << sock.local_endpoint() << endl;

}

void Client::dialogue_avec_serveur(void)
{
  //==============================//
  // RÉCEPTION DONNÉES DU SERVEUR //
  //==============================//

  cout<<"Réception d'un entier..."<<endl;
  unsigned long entier_recu=0;

  entier_recu = EnvoiReception::recevoir_entier(sock);

  cout<<"Le serveur a envoyé l'entier "+to_string(entier_recu)<<endl;

  string chaine_recue;

  chaine_recue = EnvoiReception::recevoir_chaine(sock);

  cout<<"Le serveur a envoyé la chaîne : "<<chaine_recue<<endl;


  //==========================//
  // ENVOI DONNÉES AU SERVEUR //
  //==========================//

  unsigned long entier = 420;

  // On envoie un entier au serveur
  cout<<"Envoi de l'entier "<<entier<<"..."<<flush;
  sleep(2);

  EnvoiReception::envoyer_entier(sock, entier);

  cout<<"OK"<<endl;

  // On envoie une chaîne au serveur
  cout<<"Envoi d'une chaîne..."<<flush;
  sleep(2);

  EnvoiReception::envoyer_chaine(sock, "Salut, je suis le client !");

  cout<<"OK"<<endl;

  // on attend un peu avant de fermer la connexion TCP
  sleep(10); // sleep() est plus simple et ne nécessite pas d'inclure <thread>
}
