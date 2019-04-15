#include <iostream>
#include <thread>

#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

// TODO Bonus : déclarer une constante N pour le nombre maximal de clients connectés

Serveur::Serveur(unsigned short n_port) :
  socket_ecoute(service_es,
		tcp::endpoint(tcp::v4(), n_port))
{
  // Valeur par défaut numero_nouveau_client
  numero_nouveau_client = 1;
}


[[noreturn]] void Serveur::attend_clients(void)
{
  mutex_cout.lock();
  cout<<"Adresse IP et n° de port côté serveur : "<<socket_ecoute.local_endpoint()<<endl;
  cout<<"En attente d'un client..."<<endl;
  mutex_cout.unlock();

  // boucle infinie pour attendre les nouveaux clients
  while(true) {

    // Créer un objet ClientConnecte
    ClientConnecte client(numero_nouveau_client, *this);

    // Attendre une connexion TCP
    socket_ecoute.accept(client.sock);

    // Stocker l'objet ClientConnecte dans la map
    // (attention à l'exclusion mutuelle)
    mutex_clients.lock();

    clients.emplace(numero_nouveau_client, move(client));

    ClientConnecte& client_ref = clients.at(numero_nouveau_client);

    mutex_clients.unlock();

    // Afficher les paramètres IP du client
    mutex_cout.lock();
    cout << "Client connecté : n°" << numero_nouveau_client << endl;
    cout << "Paramètres IP client : " << client_ref.sock.remote_endpoint() << endl;
    cout << "Paramètres IP socket de transfert : " << client_ref.sock.local_endpoint() << endl;
    mutex_cout.unlock();

    // Envoyer au client son numéro
    EnvoiReception::envoyer_entier(client_ref.sock, numero_nouveau_client);

    // V2: Annoncer à tous les clients l'arrivée d'un nouveau client
    envoyer_message_vers_tous_clients(0, "Connexion du client n°" + to_string(numero_nouveau_client)); // 0 = n° spécial représentant le serveur

    // Lancer le thread ThreadClient
    mutex_cout.lock();
      cout<<"Nombre de clients : "<<nb_clients()<<endl;
    mutex_cout.unlock();

    std::thread thClient(ThreadClient(client_ref, numero_nouveau_client));
    thClient.detach();

    // Incrémentation du numéro client
    numero_nouveau_client++;
  }
}

// Attention : pas const car on modifie un mutex
unsigned long Serveur::nb_clients(void)
{
  // Exclusion mutuelle
  mutex_clients.lock();
  unsigned long nbClients = clients.size();
  mutex_clients.unlock();

  return nbClients;
}

void Serveur::envoyer_message_vers_tous_clients(unsigned long numero_client, const std::string& chaine)
{
  // V2 : Parcourir la map et envoyer la chaîne à tous les *autres* clients
  // V2 : Exclusion mutuelle
  mutex_clients.lock();

  for(std::map<unsigned long, ClientConnecte>::iterator it = clients.begin(); it != clients.end(); ++it)
  {
    // Tester si le numéro du client n'est pas le même que celui qui a envoyé le message
    if (it->second.numero_client != numero_client) {
      EnvoiReception::envoyer_entier(it->second.sock, numero_client);
      EnvoiReception::envoyer_chaine(it->second.sock, chaine);
    }
  }

  mutex_clients.unlock();
}
