#include <iostream>

#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

Serveur::Serveur(unsigned short n_port) :
// On initialise un socket d'écoute rattaché au port
socket_ecoute(service_es, tcp::endpoint(tcp::v4(), n_port))
{

}
//---------------------------------------------------------------------------------/

[[noreturn]] void Serveur::attend_clients(void)
{
  // Afficher adresse IP et port locaux du socket d'écoute
  cout << "Paramètres IP serveur : " << socket_ecoute.local_endpoint() << endl;

  unsigned long entier=42;

  // on va traiter plusieurs clients séquentiellement
  while(true) {

    // Déclaration d'un socket
    boost::asio::ip::tcp::socket sock(service_es);

    cout<<"En attente d'un client..."<<endl;

    // Aattendre une connexion TCP
    socket_ecoute.accept(sock);

    // Afficher adresse IP et n°port du client
    // Afficher adresse IP et n°port du socket de transfert
    cout << "Paramètres IP client : " << sock.remote_endpoint() << endl;
    cout << "Paramètres IP socket de transfert : " << sock.local_endpoint() << endl;

    //=========================//
    // ENVOI DONNÉES AU CLIENT //
    //=========================//

    // On envoie un entier au client
    cout<<"Envoi de l'entier "<<entier<<"..."<<flush;
    sleep(2);

    EnvoiReception::envoyer_entier(sock, entier);

    cout<<"OK"<<endl;

    // On envoie une chaîne au client
    cout<<"Envoi d'une chaîne..."<<flush;
    sleep(2);

    EnvoiReception::envoyer_chaine(sock, "Salut, je suis le serveur !");

    cout<<"OK"<<endl;


    //=============================//
    // RÉCEPTION DONNÉES DU CLIENT //
    //=============================//

    cout<<"Réception d'un entier..."<<endl;
    unsigned long entier_recu=0;

    entier_recu = EnvoiReception::recevoir_entier(sock);

    cout<<"Le client a envoyé l'entier "+to_string(entier_recu)<<endl;

    string chaine_recue;

    chaine_recue = EnvoiReception::recevoir_chaine(sock);

    cout<<"Le client a envoyé la chaîne : "<<chaine_recue<<endl;


    // on attend un peu avant de fermer la connexion TCP
    sleep(10); // sleep() est plus simple et ne nécessite pas d'inclure <thread>

    entier++;
  }
}
